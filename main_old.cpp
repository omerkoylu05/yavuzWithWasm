#include <iostream>
#include <stdio.h>
#include <cstring>
#include <limits>
#include "./src/libchess/position.hpp"
#include <math.h>

extern "C" {

using namespace std;
using namespace libchess;

char* startFen=(char *)"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
char * ex1=(char *)"rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2";
char* example=(char *)"r1b1k1nr/p2p1pNp/n2B4/1p1NP2P/6P1/3P1Q2/P1P1K3/q5b1";
int depth=3;
    Side s=Side::White;

    int startConstant=0;

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

    int set_side(int side) {
        side==0?startConstant=startConstant:startConstant=-startConstant;
        if (side!=s) {
            int temp=0;
            int temp2=0;
            for (int i=0;i<6;i++) {
                for (int s=0;s<64;s++) {
                    temp=opPoints[i][s];
                    opPoints[i][s]=pPoints[i][s];
                    pPoints[i][s]=temp;
                    temp2=addperMove[i][s];
                    addperMove[i][s]=oaddperMove[i][s];
                    oaddperMove[i][s]=temp2;
                }
            }
        }
        s=Side(side);
        return 0;
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
        return 0;
    }

    int prev() {
        for (int t=0;t<6;t++) {
            for (int i=0;i<64;i++) {
                pPoints[t][i]=(int)((sigmoid(inverseSigmoid((float)pPoints[t][i]/1000)-((float)addperMove[t][i]/1000)))*1000);
                opPoints[t][i]=(int)((sigmoid(inverseSigmoid((float)pPoints[t][i]/1000)-((float)addperMove[t][i]/1000)))*1000);
            }
        }
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

    int* minmax(string fen, int dpth, int alpha, int beta, bool maximizingPlayer,Move mo,int val) {
        Position pxf(fen);
        int *ret=new int[2];
        ret[0]=dpth;
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
        int retvalue=calcGainDiff(maximizingPlayer,mo,val);
        // cout<<"son deger"<<endl;
        // cout<<retvalue<<endl;
        if (dpth == 0) {
            ret[1]=retvalue;
            // cout<<"buradan döndüm"<<endl;
            // cout<<retvalue<<endl;
            // cout<<ret[1]<<endl;
            return ret;
        }
        if (maximizingPlayer) {
            int value = numeric_limits<int>::min();
            vector<Move> moves=pxf.legal_moves();
            for (const auto m: moves ) {
                pxf.makemove(m);
                value = max(value, minmax(pxf.get_fen(), dpth - 1, alpha, beta, !maximizingPlayer, m,retvalue)[1]);
                pxf.undomove();
                if (value >= beta)
                    break;
                alpha = max(alpha, value);
            }
            ret[1]=value;
            return ret;
        } else {
            int value = numeric_limits<int>::max();
            vector<Move> moves=pxf.legal_moves();
            for (const auto m: moves ) {
                pxf.makemove(m);
                value = min(value, minmax(pxf.get_fen(), dpth - 1, alpha, beta, !maximizingPlayer, m, retvalue)[1]);
                pxf.undomove();
                if (value <=alpha)
                    break;
                beta = min(beta, value);
            }
            ret[1]=value;
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
        int bestDepth=0;
        int bestGain=numeric_limits<int>::min();
        // if (depth%2==0) {
        //     bestGain=numeric_limits<float>::infinity();
        //     bestDepth=3.0;
        //     }
        vector<Move> moves=pos.legal_moves();
        int idx=0;
        int retvalue=calcGain(pos);//-numeric_limits<float>::infinity();//calcGain(pos);
        // cout<<"retvalue"<<endl;
        // cout<<retvalue<<endl;
        for (const auto m : moves) {
            pos.makemove(m);
            int *val=minmax(pos.get_fen(),depth-1,numeric_limits<int>::min(),numeric_limits<int>::max(),false,m,retvalue);
            cout<<val[1]<<endl;
            pos.undomove();
            // if (depth%2==1) {
                if (val[1]==bestGain) {
                    if (val[0]>=bestDepth) {
                        bestDepth=val[0];
                        bestMove=m;
                    }
                } else if (val[1]>bestGain) {
                    bestGain=val[1];
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

        string bData=bestMove.operator std::string();
        char *ret=new char[bData.length()+1];
        strcpy(ret,bData.c_str());
        return ret;
        // // char *ret;
        // return ret;
    }

    int main() {
        // string s(startFen);
        float **vals=new float*[6]();
        float **vals2=new float*[6]();
        float **vals3=new float*[6]();
        float **vals4=new float*[6]();
        for (int i=0;i<6;i++) {
            vals[i]=new float[64];
            vals2[i]=new float[64];
            vals3[i]=new float[64];
            vals4[i]=new float[64];
        }

        for (int i=0;i<6;i++) {
            for (int s=0;s<64;s++) {
                vals[i][s]=0.999f;
                vals2[i][s]=0.999f;
                vals3[i][s]=0.000f;
                vals4[i][s]=0.000f;
            }
        }
        set_piecePoints(vals,vals2,vals3,vals4);

        // cout<<pPoints[0][16];
        char* m=selectBest(ex1);
        // // char* f=(char *)"test.txt";
        // // initValues(f);
        // // Position pos(s);
        // // cout<<s;
        // // char *a=selectBest(startFen);
        // // // if (pos.board[0][0][0]=='r') cout<<"true"<<endl;
        // // // cout<<pos;
        cout<<m;
        return 0;
    } 

}