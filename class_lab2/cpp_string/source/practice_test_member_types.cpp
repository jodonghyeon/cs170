#include "practice_string.hpp"

#include <type_traits>

#include "unit_tests.hpp"

TEST_CASE("member types")
{
    using str = CS170::practice_string;

    CHECK_UNARY(std::is_same_v<str::size_type, int>);
    CHECK_UNARY(std::is_same_v<str::reference, char&>);
    CHECK_UNARY(std::is_same_v<str::const_reference, const char&>);
    CHECK_UNARY(std::is_same_v<str::pointer, char*>);
    CHECK_UNARY(std::is_same_v<str::const_pointer, const char*>);
}
