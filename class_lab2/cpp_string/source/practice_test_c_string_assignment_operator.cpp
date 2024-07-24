#include "practice_string.hpp"

#include "unit_tests.hpp"

TEST_CASE("c string assignment operator")
{
    using str = CS170::practice_string;

    str s1{};
    s1 = ("'And what is the use of a book,' thought Alice, 'without pictures or conversation?");
    CHECK_UNARY(!s1.is_empty());
    CHECK_EQ(s1.length(), 82);
    CHECK_EQ(s1, ("'And what is the use of a book,' thought Alice, 'without pictures or conversation?"));
}
