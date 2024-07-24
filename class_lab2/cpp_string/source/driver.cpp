#ifdef _WIN32
#    define _CRTDBG_MAP_ALLOC
#    include <crtdbg.h>
#    include <cstdlib>
#endif

#include "practice_string.hpp"

//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_IMPLEMENT
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
#include "unit_tests.hpp"


int main(int argc, char** argv)
{
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    doctest::Context context;
    context.applyCommandLine(argc, argv);
    return context.run();
}
