add_executable(test_core
	"core_tests.cpp"
	"test_application.cpp"
	"mock_application.h"
	"test_state_storage_heap.cpp"
	"test_geom.cpp")

target_link_libraries(test_core gtest_main gmock_main sgl)
gtest_discover_tests(test_core)