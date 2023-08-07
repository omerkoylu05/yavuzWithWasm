#include <libchess/position.hpp>
#include <string>
#include "catch.hpp"

TEST_CASE("Position::get_fen()") {
    const std::string fens[] = {
        "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1",
        "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w K - 0 1",
        "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w Q - 0 1",
        "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w k - 0 1",
        "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b q - 0 1",
        "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b - - 0 1",
        "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b Kk - 0 1",
        "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b Qq - 0 1",
        "2rq1rk1/pp1bppbp/2np1np1/8/3NP3/1BN1BP2/PPPQ2PP/2KR3R b - - 8 11",
        "2rqr1k1/pp1bppbp/3p1np1/4n3/3NP2P/1BN1BP2/PPPQ2P1/1K1R3R b - - 0 13",
        "rnbqkbnr/ppp1pppp/8/8/3pP3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 3",
    };

    for (const auto& fen : fens) {
        libchess::Position pos{fen};
        REQUIRE(pos.get_fen() == fen);
    }
}

TEST_CASE("Counters") {
    const std::tuple<std::string, int, int> moves[] = {
        {"e2e4", 0, 1},
        {"c7c5", 0, 2},
        {"g1f3", 1, 2},
        {"d7d6", 0, 3},
        {"d2d4", 0, 3},
        {"c5d4", 0, 4},
        {"f3d4", 0, 4},
        {"g8f6", 1, 5},
        {"b1c3", 2, 5},
        {"g7g6", 0, 6},
        {"c1e3", 1, 6},
        {"f8g7", 2, 7},
        {"f1e2", 3, 7},
        {"e8g8", 4, 8},
        {"e1g1", 5, 8},
    };

    auto pos = libchess::Position{"startpos"};
    for (const auto& [str, half, full] : moves) {
        INFO(str);
        for (const auto& move : pos.legal_moves()) {
            if (static_cast<std::string>(move) == str) {
                pos.makemove(move);
                break;
            }
        }
        REQUIRE(pos.halfmoves() == half);
        REQUIRE(pos.fullmoves() == full);
    }
}
