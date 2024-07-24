#include "practice_string.hpp"

#include "unit_tests.hpp"

TEST_CASE("copy assignment operator")
{
    using str = CS170::practice_string;

    str       s1{};
    const str s2{("It would have made a dreadfully ugly child; but it makes rather a handsome pig.")};
    s1 = s2;
    CHECK_EQ(s1, s2);
    CHECK_NE(s1.as_c_string(), s2.as_c_string());
}
