#include "practice_string.hpp"

#include "unit_tests.hpp"

TEST_CASE("empty ctor")
{
    using str = CS170::practice_string;
    const str s{};
    CHECK_UNARY(s.is_empty());
    CHECK_EQ(s.length(), 0);
}
