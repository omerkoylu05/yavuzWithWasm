#include <libchess/position.hpp>
#include <string>
#include "catch.hpp"

const std::pair<libchess::Bitboard, std::string> positions[] = {
    {0xffff7e, "startpos"},
    {0x3e3e3e1c000000, "b2r2b1/8/2PPP3/q1PKP1r1/2PPP3/8/b2r2q1/7k w - - 0 1"},
    {0xff3f3f3e1f0dff09, "B2R4/8/2PPP2k/Q1PKP3/2PPP3/8/3R4/8 w - - 0 1"},
    {0x818181818181b97e, "r3k2r/8/8/8/8/8/8/R3K2R w KQkq - 0 1"},
    {0x78cc38ec7800, "7k/8/4r2b/8/4NN2/4K3/8/8 w - - 0 1"},
    {0xa87ccc7cec7800, "7k/8/4r2b/4N1N1/4NN2/4K3/8/8 w - - 0 1"},
    {0x78b8808080808080, "R3k2r/8/8/8/8/8/8/4K2R b Kk - 0 1"},
    {0x119a553aff3e6dba, "1k6/8/8/1B6/4Q3/3PP3/1R1PK3/8 w - - 0 1"},
    {0x280000003828, "4k3/8/4r3/3pP3/8/8/8/4K3 w - d6 0 2"},
    {0x7dfbb5b699af93a9, "4k2q/1p6/3p4/r1n5/6b1/8/6p1/4K3 b - - 0 1"},
};

TEST_CASE("Position::squares_attacked()") {
    for (const auto& [ans, fen] : positions) {
        libchess::Position pos{fen};
        INFO(fen);
        CHECK(pos.squares_attacked(pos.turn()) == ans);
    }
}
