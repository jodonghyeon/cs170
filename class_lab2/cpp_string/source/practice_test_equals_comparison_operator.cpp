#include "practice_string.hpp"

#include "unit_tests.hpp"


TEST_CASE("equals comparison operator")
{
    using str = CS170::practice_string;
    const str s{("It's no use going back to yesterday, because I was a different person then.")};
    SUBCASE("Compare with c string")
    {
        CHECK_EQ(s, ("It's no use going back to yesterday, because I was a different person then."));
        CHECK_EQ(("It's no use going back to yesterday, because I was a different person then."), s);
    }
    SUBCASE("Compare with string obj")
    {
        const str another{("It's no use going back to yesterday, because I was a different person then.")};
        CHECK_EQ(s, another);
    }
}
