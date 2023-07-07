cmake_minimum_required(VERSION 3.14)

if (${CMAKE_VERSION} VERSION_GREATER "3.24.0")
	cmake_policy(SET CMP0135 NEW)
endif()

project(sgl)

include(CTest)
include(FetchContent)

set(SGL_CXX_STANDARD "20" CACHE STRING "C++ Language Standard")
set_property(CACHE SGL_CXX_STANDARD PROPERTY STRINGS "20" "23")

set(SGL_BACKEND_SDL ON CACHE BOOL "Enable SDL Backend")

add_subdirectory(src)
add_subdirectory(demo)

if (BUILD_TESTING)
	set(CMAKE_CXX_STANDARD "${SGL_CXX_STANDARD}")
	set(CMAKE_CXX_STANDARD_REQUIRED ON)

	FetchContent_Declare(
	  googletest
	  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
	)
	# For Windows: Prevent overriding the parent project's compiler/linker settings
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
	FetchContent_MakeAvailable(googletest)
	include(GoogleTest)
	add_subdirectory(test)
endif()
