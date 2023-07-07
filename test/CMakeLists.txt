	add_executable(test_core "core_tests.cpp")
	target_link_libraries(test_core gtest_main gmock_main sgl)
	gtest_discover_tests(test_core)
