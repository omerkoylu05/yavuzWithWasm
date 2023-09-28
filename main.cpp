#include <iostream>
#include <stdio.h>
#include <cstring>
#include <limits>
#include <chrono>
#include <algorithm>
#include <random>
#include "./src/libchess/position.hpp"

#include <math.h>

extern "C" {

using namespace std;
using namespace libchess;
using Clock = std::chrono::steady_clock;
using std::chrono::time_point;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using namespace std::literals::chrono_literals;

char* startFen=(char *)"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
char * ex1=(char *)"rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2";
char* example=(char *)"r1b1k1nr/p2p1pNp/n2B4/1p1NP2P/6P1/3P1Q2/P1P1K3/q5b1";
int depth=3;
    Position startPos(startFen);
    Side s=Side::White;

    int startConstant=0;
    int timeLimit=250;
    int c_centerControl=5;
    int c_developPieces=1;
    int c_kingProtection=1;
    int c_materialandSafety=1;
    int c_rookandPawnMovement=1;
    int ce_kingActivity=1;
    int ce_kingProtection=1;
    int ce_materialandSafety=1;
    int ce_passedPawns=2;
    int moveCount=0;

    int pieceValues[6]={
        1,//0.1000,
        1,//0.330,
        1,//0.320,
        1,//0.500,
        1,//0.900,
        1//1.00
    };

    enum types : int
    {
        p = 0,
        n,
        b,
        r,
        q,
        k,
    };

    int pPoints[6][64];
    int addperMove[6][64];

    int opPoints[6][64];
    int oaddperMove[6][64];

    float sigmoid (float t) {
        return 1/(1+pow(M_E, -t));
    }

    float inverseSigmoid (float t) {
        return log(t/(1-t));
    }
    // struct piecePoints pPoints;
    // vector<float> nodeTree{};
    int set_depth(int d) {
        depth=d;
        return 0;
    }

    int set_time_limit(int t) {
        timeLimit=t;
        return 0;
    }

    int set_side(int side) {
        cout<<side<<endl;
        s=Side(s);
        moveCount=0;
        return 0;
        // side==0?startConstant=startConstant:startConstant=-startConstant;
        // if (side!=s) {
        //     int temp=0;
        //     int temp2=0;
        //     for (int i=0;i<6;i++) {
        //         for (int s=0;s<64;s++) {
        //             temp=opPoints[i][s];
        //             opPoints[i][s]=pPoints[i][s];
        //             pPoints[i][s]=temp;
        //             temp2=addperMove[i][s];
        //             addperMove[i][s]=oaddperMove[i][s];
        //             oaddperMove[i][s]=temp2;
        //         }
        //     }
        // }
    }

    int* get_points(int index) {
        return pPoints[index];
    }

    int get_type(char c) {
        char pieces[7]="pnbrqk";
        int i=0;
        for (const auto ch: pieces) {
            if (ch==c) return i;
            i++;
        }
        return 0;
    }

    int calcStartConstant(char *fen) {

        int value=0;

        int index=0;
        // cout<<fen<<endl;
        for (int i=0;i<sizeof(fen);i++) {
            int coef=1;
            if (s==Side::Black) coef=-1;
            // cout<<fen.at(i)<<endl;
            if (fen[i]==' ') break;
            int c=int(fen[i]);
            if (c>57) {
                    if (c>=65&&c<=122) {
                        char type='?';
                        if (c>97) {
                            type=char(c);
                            coef*=-1;
                            int t=get_type(type);
                            value+=(opPoints[t][64-index]*pieceValues[t])*coef;
                            } else {
                            type=char(c+32);
                            int t=get_type(type);
                            value+=(pPoints[t][index]*pieceValues[t])*coef;
                        }
                        // value+=(pPoints[t][index]*pieceValues[t])*coef;
                        index++;
                    }
                } else {
                    if (c!=47) index+=(c-48);
                }
        }
        // cout<<value;
        return value;
    }

    void set_Coefs(float centerControl,float developPieces, float kingProtection, float materialandSafety, float rookandPawnMovement,
    float ekingProtection, float ekingActivity, float ematerialandSafety, float epassedPawns) {
        c_centerControl=centerControl*100;
        c_developPieces=developPieces*100;
        c_kingProtection=kingProtection*100;
        c_materialandSafety=materialandSafety*100;
        c_rookandPawnMovement=rookandPawnMovement*100;
        ce_kingProtection=ekingProtection*100;
        ce_kingActivity=ekingActivity*100;
        ce_materialandSafety=ematerialandSafety*100;
        ce_passedPawns=epassedPawns*100;
    }

    int calcCenterControl(Position pos) {
        int val=0;
        Square center[4]={  Square("e3"),
                            Square("e4"),
                            Square("d3"),
                            Square("d4") };
        for(int i=0;i<4;i++) {
            val+=pos.attackers(center[i], s).count();
            val-=pos.attackers(center[i], operator!(s)).count();
            val+=pos.pieces(s, Piece::Pawn).get(center[i]);
            val-=pos.pieces(operator!(s), Piece::Pawn).get(center[i]);
            val+=pos.pieces(s, Piece::Bishop).get(center[i]);
            val-=pos.pieces(operator!(s), Piece::Bishop).get(center[i]);
            val+=pos.pieces(s, Piece::Knight).get(center[i]);
            val-=pos.pieces(operator!(s), Piece::Knight).get(center[i]);
            val+=pos.pieces(s, Piece::Rook).get(center[i]);
            val-=pos.pieces(operator!(s), Piece::Rook).get(center[i]);
            val+=pos.pieces(s, Piece::Queen).get(center[i]);
            val-=pos.pieces(operator!(s), Piece::Queen).get(center[i]);
            val+=pos.pieces(s, Piece::King).get(center[i]);
            val-=pos.pieces(operator!(s), Piece::King).get(center[i]);
        };
        return val*100;
    }

    int calcDevelopPieces(Position pos) {
        int val=0;
        Bitboard b=startPos.occupancy(s).operator^(pos.occupancy(s));
        val+=(b.count()/2);
        b=startPos.occupancy(operator!(s)).operator^(pos.occupancy(operator!(s)));
        val-=(b.count()/2);
        return val*100;
    }
    
    int calcKingProtection(Position pos) {
        int val=0;

        Square kp=pos.king_position(s);
        int kpi=kp.operator int();
        Bitboard kingEnvironment;
        Bitboard opponentKingEnvironment;
        // try {

        // } catch( const __assert_fail e) {

        // }
        int kpe[9] = {
            // -1,-1,-1,-1,-1,-1,-1,-1
            kpi,
            kpi+8<64?kpi+8:-1,
            kpi-8>0?kpi-8:-1,
            kpi+1<64?kpi+1:-1,
            kpi-1>0?kpi-1:-1,
            kpi+7<64?kpi+7:-1,
            kpi+9<64?kpi+9:-1,
            kpi-9>0?kpi-9:-1,
            kpi-7>0?kpi-7:-1
        };
        kp=pos.king_position(operator!(s));
        kpi=kp.operator int();
        int okpe[9] = { 
            // -1,-1,-1,-1,-1,-1,-1,-1
            kpi,
            kpi+8<64?kpi+8:-1,
            kpi-8>0?kpi-8:-1,
            kpi+1<64?kpi+1:-1,
            kpi-1>0?kpi-1:-1,
            kpi+7<64?kpi+7:-1,
            kpi+9<64?kpi+9:-1,
            kpi-9>0?kpi-9:-1,
            kpi-7>0?kpi-7:-1
        };
        for(int i=0;i<9;i++) {
            if (kpe[i]!=-1) {
                kingEnvironment.set(kpe[i]);
                val+=pos.attackers(kpe[i],s).count();
                val-=pos.attackers(kpe[i],operator!(s)).count();
            }
            if (okpe[i]!=-1) {
                opponentKingEnvironment.set(okpe[i]);
                val+=pos.attackers(okpe[i],s).count();
                val-=pos.attackers(okpe[i],operator!(s)).count();
            }
        }
        val+=(pos.occupancy(s).operator&(kingEnvironment)).count();
        val-=(pos.occupancy(operator!(s)).operator&(kingEnvironment)).count();
        val+=(pos.occupancy(s).operator&(opponentKingEnvironment)).count();
        val-=(pos.occupancy(operator!(s)).operator&(opponentKingEnvironment)).count();

        return val*100;

    }

    int calcMaterialandSafety(Position pos) {
        int val=0;
        val+=pos.pieces(s,Piece::Pawn).count()*1000;
        val+=pos.pieces(s,Piece::Bishop).count()*3300;
        val+=pos.pieces(s,Piece::Knight).count()*3200;
        val+=pos.pieces(s,Piece::Rook).count()*5000;
        val+=pos.pieces(s,Piece::Queen).count()*9000;

        val-=pos.pieces(operator!(s),Piece::Pawn).count()*1000;
        val-=pos.pieces(operator!(s),Piece::Bishop).count()*3300;
        val-=pos.pieces(operator!(s),Piece::Knight).count()*3200;
        val-=pos.pieces(operator!(s),Piece::Rook).count()*5000;
        val-=pos.pieces(operator!(s),Piece::Queen).count()*9000;

        val+=(pos.squares_attacked(s).operator&(pos.occupied()).count()*100);
        val-=(pos.squares_attacked(operator!(s)).operator&(pos.occupied()).count()*100);
        val+=(pos.squares_attacked(s).count()*100);
        val-=(pos.squares_attacked(operator!(s)).count()*100);
        return val;
    }

    int calcRookandPawnMovement(Position pos) {
        int val=0;
        Bitboard b=startPos.pieces(s,Piece::Pawn)^pos.pieces(s,Piece::Pawn);
        val-=(b.count()/2);
        b=startPos.pieces(operator!(s),Piece::Pawn)^pos.pieces(operator!(s),Piece::Pawn);
        val+=(b.count()/2);
        if (pos.can_castle(s,MoveType::ksc)) val++;
        if (pos.can_castle(s,MoveType::qsc)) val++;
        if (pos.can_castle(operator!(s),MoveType::ksc)) val--;
        if (pos.can_castle(operator!(s),MoveType::qsc)) val--;
        return val*100;
    }   

    int calcRook(Position pos) {
        int val=0;
        return val*100;
    }

    int calcKingActivity(Position pos) {
        int val=0;
        val+=pos.king_allowed(s).count();
        val-=pos.king_allowed(operator!(s)).count();
        return val*100;
    }

    int calcPassedPawns(Position pos) {
        int val=0;
        val+=pos.passed_pawns(s).count();
        val-=pos.passed_pawns(operator!(s)).count();
        return val*100;
    }

    int midgameEvaluate(Position pos) {
        int val=0;
        val+=(c_centerControl*calcCenterControl(pos));
        val+=(c_developPieces*calcDevelopPieces(pos));
        val+=(c_kingProtection*calcKingProtection(pos));
        val+=(c_materialandSafety*calcMaterialandSafety(pos));
        val+=(c_rookandPawnMovement*calcRookandPawnMovement(pos));
        // cout<<"midgame:"<<val<<endl;
        return val;
    }

    int endGameEvaluate(Position pos) {
        int val=0;
        val+=(ce_kingActivity*calcKingActivity(pos));
        val+=(ce_kingProtection*calcKingProtection(pos));
        val+=(ce_materialandSafety*calcMaterialandSafety(pos));
        val+=(ce_passedPawns*calcPassedPawns(pos));
        // cout<<"endgame:"<<val<<endl;
        return val;
    }

    int evaluate(Position pos) {
        int val=0;
        int midCoef=(1000-(15*moveCount));
        if (midCoef>0) val+=(midCoef*midgameEvaluate(pos));
        int endCoef=moveCount*15;
        if (endCoef>1000) endCoef=1000;
        val+=(endCoef*endGameEvaluate(pos));
        return val;
    }
    

    int set_piecePoints(float **vals, float **vals2, float **vals3, float **vals4) {
        for (int p=0;p<64;p++) {
            pPoints[0][p]=(int)(vals[0][p]*1000);
            pPoints[1][p]=(int)(vals[1][p]*1000);
            pPoints[2][p]=(int)(vals[2][p]*1000);
            pPoints[3][p]=(int)(vals[3][p]*1000);
            pPoints[4][p]=(int)(vals[4][p]*1000);
            pPoints[5][p]=(int)(vals[5][p]*1000);
            addperMove[0][p]=(int)(vals2[0][p]*1000);
            addperMove[1][p]=(int)(vals2[1][p]*1000);
            addperMove[2][p]=(int)(vals2[2][p]*1000);
            addperMove[3][p]=(int)(vals2[3][p]*1000);
            addperMove[4][p]=(int)(vals2[4][p]*1000);
            addperMove[5][p]=(int)(vals2[5][p]*1000);
            opPoints[0][p]=(int)(vals3[0][p]*1000);
            opPoints[1][p]=(int)(vals3[1][p]*1000);
            opPoints[2][p]=(int)(vals3[2][p]*1000);
            opPoints[3][p]=(int)(vals3[3][p]*1000);
            opPoints[4][p]=(int)(vals3[4][p]*1000);
            opPoints[5][p]=(int)(vals3[5][p]*1000);
            oaddperMove[0][p]=(int)(vals4[0][p]*1000);
            oaddperMove[1][p]=(int)(vals4[1][p]*1000);
            oaddperMove[2][p]=(int)(vals4[2][p]*1000);
            oaddperMove[3][p]=(int)(vals4[3][p]*1000);
            oaddperMove[4][p]=(int)(vals4[4][p]*1000);
            oaddperMove[5][p]=(int)(vals4[5][p]*1000);
        }
        startConstant=calcStartConstant(startFen);
        return 0;
    }

    int next() {
        for (int t=0;t<6;t++) {
            for (int i=0;i<64;i++) {
                pPoints[t][i]=(int)((sigmoid(inverseSigmoid((float)pPoints[t][i]/1000)+((float)addperMove[t][i]/1000)))*1000);
                opPoints[t][i]=(int)((sigmoid(inverseSigmoid((float)opPoints[t][i]/1000)+((float)oaddperMove[t][i]/1000)))*1000);
            }
        }
        moveCount++;
        return 0;
    }

    int prev() {
        for (int t=0;t<6;t++) {
            for (int i=0;i<64;i++) {
                pPoints[t][i]=(int)((sigmoid(inverseSigmoid((float)pPoints[t][i]/1000)-((float)addperMove[t][i]/1000)))*1000);
                opPoints[t][i]=(int)((sigmoid(inverseSigmoid((float)pPoints[t][i]/1000)-((float)addperMove[t][i]/1000)))*1000);
            }
        }
        moveCount--;
        return 0;
    }

    int calcGain(Position pos) {

        if (pos.legal_moves().size()==0) {
            if (pos.turn()==s&&pos.in_check()) {
                return numeric_limits<int>::min();
            } else {
                return numeric_limits<int>::max();
            }
        }

        int value=0;

        string fen=pos.get_fen();
        int n = fen.length();
 
        // declaring character array
        char fenc[n + 1];
 
        // copying the contents of the
        // string to char array
        strcpy(fenc, fen.c_str());
        int index=0;
        // cout<<fen<<endl;
        for (int i=0;i<sizeof(fenc);i++) {
            int coef=1;
            if (s==Side::Black) coef=-1;
            // cout<<fen.at(i)<<endl;
            if (fenc[i]==' ') break;
            int c=int(fenc[i]);
            if (c>57) {
                    if (c>=65&&c<=122) {
                        char type='?';
                        if (c>97) {
                            type=char(c);
                            coef*=-1;
                            int t=get_type(type);
                            value+=(opPoints[t][index]*coef);//pieceValues[t])*coef;
                            } else {
                            int t=get_type(type);
                            value+=(pPoints[t][index]*coef);//pieceValues[t])*coef;
                            type=char(c+32);
                        }
                        index++;
                    }
                } else {
                    if (c!=47) index+=(c-48);
                }
        }
        return value-startConstant;
    }

    int calcGainDiff(bool max,Move m,int value) {

        int coef=1;
        if (max) {
        coef=-1; 
        value-=opPoints[(int)m.piece()][(int)m.from()]*coef;//pieceValues[(int)m.piece()]*coef;
        // cout<<value<<endl;
            if (m.captured()!=Piece::None) {
                value+=pPoints[(int)m.captured()][(int)m.to()]*coef;//pieceValues[(int)m.captured()]*coef;
                // cout<<value<<endl;
            }
            if (m.promotion()!=Piece::None) {
                value+=opPoints[(int)m.promotion()][(int)m.to()]*coef;//pieceValues[(int)m.promotion()]*coef;
            } else {
                value+=opPoints[(int)m.piece()][(int)m.to()]*coef;//pieceValues[(int)m.piece()]*coef;
            }
            // cout<<value<<endl;
            return value;
        } else {
            coef=1;
            value-=pPoints[(int)m.piece()][(int)m.from()]*coef;//pieceValues[(int)m.piece()]*coef;
            // cout<<value<<endl;
            if (m.captured()!=Piece::None) {
                value+=opPoints[(int)m.captured()][(int)m.to()]*coef;//pieceValues[(int)m.captured()]*coef;
                // cout<<value<<endl;
            }
            if (m.promotion()!=Piece::None) {
                value+=pPoints[(int)m.promotion()][(int)m.to()]*coef;//pieceValues[(int)m.promotion()]*coef;
            } else {
                value+=pPoints[(int)m.piece()][(int)m.to()]*coef;//pieceValues[(int)m.piece()]*coef;
            }
            // cout<<value<<endl;
            // value*=1000000.0f;
            // value=round(value)/1000000.0f;
            return value;
        }
    }

    int* minmax(string fen, int dpth, int alpha, int beta, bool maximizingPlayer,Move mo,int val, time_point<Clock> startTime){
        Position pxf(fen);
        int *ret=new int32_t[2];
        ret[0]=dpth;
        time_point<Clock> end = Clock::now();
        milliseconds diff = duration_cast<milliseconds>(end - startTime);

        if (pxf.legal_moves().size()==0&&pxf.in_check()) {
                if (maximizingPlayer) {
                    ret[1]=numeric_limits<int>::min(); 
                    return ret;
                }
                else
                {
                    ret[1]=numeric_limits<int>::max(); 
                    return ret;
                }
        }
        // cout<<"baslangic deger"<<endl;
        // cout<<val<<endl;
        // int retvalue=calcGainDiff(maximizingPlayer,mo,val)
        int retvalue=0;
        // cout<<"son deger"<<endl;
        // cout<<retvalue<<endl;
        if (dpth == 0|| diff.count()>timeLimit) {
            int retvalue=evaluate(pxf);
            ret[1]=retvalue;
            // cout<<"buradan döndüm"<<endl;
            // cout<<retvalue<<endl;
            // cout<<ret[1]<<endl;
            return ret;
        }
        if (maximizingPlayer) {
            int bestVal = numeric_limits<int>::min();
            vector<Move> moves=pxf.legal_moves();
            for (const auto m: moves ) {
                pxf.makemove(m);
                int value=minmax(pxf.get_fen(), dpth - 1, alpha, beta, !maximizingPlayer, m,retvalue,startTime)[1];
                bestVal = max(bestVal, value);
                if (m.type()==MoveType::ksc||m.type()==MoveType::qsc) value++;
                pxf.undomove();
                alpha = max(alpha, bestVal);
                if (beta<=alpha)
                    break;
            }
            ret[1]=bestVal;
            return ret;
        } else {
            int bestVal = numeric_limits<int>::max();
            vector<Move> moves=pxf.legal_moves();
            for (const auto m: moves ) {
                pxf.makemove(m);
                int value=minmax(pxf.get_fen(), dpth - 1, alpha, beta, !maximizingPlayer, m, retvalue, startTime)[1];
                bestVal =min(value,bestVal);
                beta=min(beta,bestVal);
                if (m.type()==MoveType::ksc||m.type()==MoveType::qsc) value--;
                pxf.undomove();
                beta = min(beta, value);
                if (beta <=alpha)
                    break;
            }
            ret[1]=bestVal;
            return ret;
        }
    }

    char* selectBest(char* fen) {
        startFen=fen;
        string f(fen);
        // return fen;
        Position pos(f);
        // vector<float> nodeTree={};
        Move bestMove;
        int bestDepth=depth;
        int bestGain=numeric_limits<int>::min();
        // if (depth%2==0) {
        //     bestGain=numeric_limits<float>::infinity();
        //     bestDepth=3.0;
        //     }
        vector<Move> moves=pos.legal_moves();
        std::cout<<(moves.size())<<endl;
        std::shuffle(moves.begin(),moves.end(),std::default_random_engine());
        std::cout<<(moves.size())<<endl;
        int idx=0;
        int retvalue=0;
        // float retvalue=evaluate(pos);//-numeric_limits<float>::infinity();//calcGain(pos);
        // cout<<"retvalue"<<endl;
        // cout<<retvalue<<endl;
        for (const auto m : moves) {
            time_point<Clock> startTime=Clock::now();
            pos.makemove(m);
            int *val=minmax(pos.get_fen(),depth-1,numeric_limits<float>::min(),numeric_limits<float>::max(),false,m,retvalue, startTime);
            int coef=(1000-(moveCount*15));
            if (coef<0) coef=0;
            if (m.type()==MoveType::ksc||m.type()==MoveType::qsc) val[1]+=100*coef*c_rookandPawnMovement;
            cout<<val[1]<<endl;
            pos.undomove();
            // if (depth%2==1) {
                if (val[1]==bestGain) {
                    if (bestGain>0) {
                        if (val[0]>=bestDepth) {
                            bestMove=m;
                            bestDepth=val[0];
                        }
                    } else {
                        if (val[0]<=bestDepth) {
                            bestMove=m;
                            bestDepth=val[0];
                        }
                    }
                } else 
                if (val[1]>bestGain) {
                    bestGain=val[1];
                    bestDepth=val[0];
                    bestMove=m;
                    }
            // } else {
            //     if (val[1]==bestGain) {
            //         if (val[0]<=bestDepth) {
            //             bestDepth=val[0];
            //             bestMove=m;
            //         }
            //     } else if (val[1]<bestGain) {
            //         bestGain=val[1];
            //         bestMove=m;
            //     }

            // }
            
        }
        cout<<bestGain<<endl;
        string bData=bestMove.operator std::string();
        char *ret=new char[bData.length()+1];
        strcpy(ret,bData.c_str());
        return ret;
        // // char *ret;
        // return ret;
    }

    // int main() {
    //     // string s(startFen);
    //     float **vals=new float*[6]();
    //     float **vals2=new float*[6]();
    //     float **vals3=new float*[6]();
    //     float **vals4=new float*[6]();
    //     for (int i=0;i<6;i++) {
    //         vals[i]=new float[64];
    //         vals2[i]=new float[64];
    //         vals3[i]=new float[64];
    //         vals4[i]=new float[64];
    //     }

    //     for (int i=0;i<6;i++) {
    //         for (int s=0;s<64;s++) {
    //             vals[i][s]=0.999f;
    //             vals2[i][s]=0.999f;
    //             vals3[i][s]=0.000f;
    //             vals4[i][s]=0.000f;
    //         }
    //     }
    //     set_piecePoints(vals,vals2,vals3,vals4);

    //     // cout<<pPoints[0][16];
    //     char* m=selectBest(ex1);
    //     // // char* f=(char *)"test.txt";
    //     // // initValues(f);
    //     // // Position pos(s);
    //     // // cout<<s;
    //     // // char *a=selectBest(startFen);
    //     // // // if (pos.board[0][0][0]=='r') cout<<"true"<<endl;
    //     // // // cout<<pos;
    //     cout<<m;
    //     return 0;
    // } 

}