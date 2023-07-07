add_executable(demo_core demo_core.cpp)
target_link_libraries(demo_core sgl)

if (${SGL_BACKEND_SDL})
	add_executable(demo_sdl demo_sdl.cpp)
	target_link_libraries(demo_sdl sgl sgl_sdl sgl_sdl_main)
endif()
