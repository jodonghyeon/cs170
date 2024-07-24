#include "practice_string.hpp"

#include "unit_tests.hpp"


TEST_CASE("+ operator")
{
    using str = CS170::practice_string;
    SUBCASE("+ c str and string types")
    {
        const str         curiouser{("curiouser")};
        const char        NULL_CHAR{0};
        const char* const nothing    = &NULL_CHAR;
        const str         main_part  = ("Curiouser") + str{(" and ")} + curiouser + nothing + nothing;
        const str         whole_part = main_part + ("!");
        CHECK_EQ(whole_part, ("Curiouser and curiouser!"));
    }
    SUBCASE("+ self")
    {
        const str abc{("abc")};
        const str s = abc + abc;
        CHECK_EQ(s, ("abcabc"));
    }
}
