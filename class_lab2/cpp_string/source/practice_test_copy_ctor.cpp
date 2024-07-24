#include "practice_string.hpp"

#include "unit_tests.hpp"

TEST_CASE("copy ctor")
{
    using str = CS170::practice_string;
    const str other{("There can be only one!?")};
    const str s{other};
    CHECK_EQ(s, other);
    CHECK_EQ(s, ("There can be only one!?"));
}
