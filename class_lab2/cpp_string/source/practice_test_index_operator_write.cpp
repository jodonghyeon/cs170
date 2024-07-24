#include "practice_string.hpp"

#include "unit_tests.hpp"

TEST_CASE("operator[] write")
{
    using str = CS170::practice_string;
    str  s{("\x1\x2\x3\x4")};
    char value{};

    SUBCASE("Positive Access")
    {
        for (str::size_type i = 0; i < s.length(); ++i)
        {
            value = static_cast<char>(s[i] + ('\x1'));
            s[i]  = value;
        }
        CHECK_EQ(s[0], ('\x2'));
        CHECK_EQ(s[1], ('\x3'));
        CHECK_EQ(s[2], ('\x4'));
        CHECK_EQ(s[3], ('\x5'));
    }
}
