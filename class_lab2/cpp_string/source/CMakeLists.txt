set(practice_tests
driver.cpp
unit_tests.hpp
practice_test_member_types.cpp
practice_test_empty_ctor.cpp
practice_test_c_string_ctor.cpp
practice_test_copy_ctor.cpp
practice_test_copy_assignment_operator.cpp
practice_test_c_string_assignment_operator.cpp
practice_test_equals_comparison_operator.cpp
practice_test_plus_assignment_operator.cpp
practice_test_index_operator_const.cpp
practice_test_index_operator_write.cpp
practice_test_to_c_str.cpp
practice_test_plus_operator.cpp
)

source_group("practice_tests" FILES ${practice_tests})

set(practice_string
practice_string.hpp practice_string.cpp
)

source_group("practice_string" FILES ${practice_string})

add_executable(practice_tests ${practice_tests} ${practice_string})

target_link_libraries(practice_tests PRIVATE project_warnings)
