#include "practice_string.hpp"

#include "unit_tests.hpp"

TEST_CASE("operator[] const")
{
    using str = CS170::practice_string;
    const str s{("\x1\x2\x3\x4")};

    SUBCASE("Positive Access")
    {
        char sum = 0;
        for (str::size_type i = 0; i < s.length(); ++i)
        {
            sum = static_cast<char>(sum + s[i]);
        }
        CHECK_EQ(sum, 10);
        CHECK_EQ(s[0], ('\x1'));
        CHECK_EQ(s[1], ('\x2'));
        CHECK_EQ(s[2], ('\x3'));
        CHECK_EQ(s[3], ('\x4'));
    }
}
