#include "practice_string.hpp"

#include "unit_tests.hpp"

TEST_CASE(" += operator")
{
    using str = CS170::practice_string;
    SUBCASE("+= c str and string types")
    {
        str               s{};
        const str         curiouser{("curiouser!")};
        const char        NULL_CHAR{0};
        const char* const nothing = &NULL_CHAR;
        s += nothing;
        ((s += ("Curiouser")) += str{(" and ")}) += curiouser;
        s += nothing;
        CHECK_EQ(s, ("Curiouser and curiouser!"));
        CAPTURE(s.as_c_string());
    }
    SUBCASE("+= self")
    {
        str s{("abc")};
        s += s;
        CHECK_EQ(s, ("abcabc"));
    }
}
