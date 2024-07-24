#include "practice_string.hpp"

#include "unit_tests.hpp"

#include <algorithm>
#include <cstring>
#include <cwchar>

TEST_CASE("as_c_string()")
{
    using str = CS170::practice_string;

    SUBCASE("Normal as_c_string use")
    {
        const char literal[] = {('W'), ('h'), ('y'), (','), (' '),  ('s'), ('o'), ('m'), ('e'), ('t'), ('i'), ('m'),
                                ('e'), ('s'), (' '), ('I'), ('\''), ('v'), ('e'), (' '), ('b'), ('e'), ('l'), ('i'),
                                ('e'), ('v'), ('e'), ('d'), (' '),  ('a'), ('s'), (' '), ('m'), ('a'), ('n'), ('y'),
                                (' '), ('a'), ('s'), (' '), ('s'),  ('i'), ('x'), (' '), ('i'), ('m'), ('p'), ('o'),
                                ('s'), ('s'), ('i'), ('b'), ('l'),  ('e'), (' '), ('t'), ('h'), ('i'), ('n'), ('g'),
                                ('s'), (' '), ('b'), ('e'), ('f'),  ('o'), ('r'), ('e'), (' '), ('b'), ('r'), ('e'),
                                ('a'), ('k'), ('f'), ('a'), ('s'),  ('t'), ('.'), (0)};
        const str  s         = literal;
        CHECK_EQ((0), *(s.as_c_string() + s.length()));
        CHECK_EQ(s.length(), std::strlen(s.as_c_string()));
        CHECK_UNARY(std::equal(s.as_c_string(), s.as_c_string() + s.length(), literal));
    }
    SUBCASE("as_c_string() with empty string")
    {
        const str s{};
        CHECK_UNARY(s.is_empty());
        REQUIRE(s.as_c_string() != nullptr);
        CHECK_EQ((0), *(s.as_c_string() + s.length()));
    }

    SUBCASE("Normal operator const char * use")
    {
        const char literal[] = {('W'), ('h'), ('y'), (','), (' '),  ('s'), ('o'), ('m'), ('e'), ('t'), ('i'), ('m'),
                                ('e'), ('s'), (' '), ('I'), ('\''), ('v'), ('e'), (' '), ('b'), ('e'), ('l'), ('i'),
                                ('e'), ('v'), ('e'), ('d'), (' '),  ('a'), ('s'), (' '), ('m'), ('a'), ('n'), ('y'),
                                (' '), ('a'), ('s'), (' '), ('s'),  ('i'), ('x'), (' '), ('i'), ('m'), ('p'), ('o'),
                                ('s'), ('s'), ('i'), ('b'), ('l'),  ('e'), (' '), ('t'), ('h'), ('i'), ('n'), ('g'),
                                ('s'), (' '), ('b'), ('e'), ('f'),  ('o'), ('r'), ('e'), (' '), ('b'), ('r'), ('e'),
                                ('a'), ('k'), ('f'), ('a'), ('s'),  ('t'), ('.'), (0)};
        const str  s         = literal;
        CHECK_EQ((0), *(static_cast<const char*>(s) + s.length()));
        CHECK_EQ(s.length(), std::strlen(static_cast<const char*>(s)));
        CHECK_UNARY(std::equal(static_cast<const char*>(s), static_cast<const char*>(s) + s.length(), literal));
    }
    SUBCASE("operator const char * with empty string")
    {
        const str s{};
        CHECK_UNARY(s.is_empty());
        REQUIRE(static_cast<const char*>(s) != nullptr);
        CHECK_EQ((0), *(static_cast<const char*>(s) + s.length()));
    }
}
