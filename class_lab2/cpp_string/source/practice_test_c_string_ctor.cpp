#include "practice_string.hpp"

#include "unit_tests.hpp"

TEST_CASE("c string ctor")
{
    using str = CS170::practice_string;
    SUBCASE("c string 14 chars")
    {
        const str s{("C Style String")};
        CHECK_UNARY(!s.is_empty());
        CHECK_EQ(s.length(), 14);
        CHECK_EQ(s, ("C Style String"));
    }

    SUBCASE("c string 52 chars")
    {
        const str s{("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")};
        CHECK_UNARY(!s.is_empty());
        CHECK_EQ(s.length(), 52);
        CHECK_EQ(s, ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"));
    }

    SUBCASE("c string 0 chars")
    {
        const str s{("")};
        CHECK_UNARY(s.is_empty());
        CHECK_EQ(s.length(), 0);
        CHECK_EQ(s, (""));
    }
}
