find_package(SDL2 REQUIRED)

add_library(sgl_sdl)
add_library(sgl_sdl_main)

file(GLOB_RECURSE SGL_SDL_PUBLIC_HEADER_FILES
    "${PROJECT_SOURCE_DIR}/include/sgl/sdl/*.h"
)

target_sources(sgl_sdl PRIVATE 
	sgl_sdl_app.cpp
	sys_info.cpp
)
target_sources(sgl_sdl PUBLIC "${SGL_SDL_PUBLIC_HEADER_FILES}")

target_link_libraries(sgl_sdl PUBLIC SDL2::SDL2 sgl)

target_sources(sgl_sdl_main PRIVATE
	sgl_sdl_main_stub.cpp)
target_link_libraries(sgl_sdl_main PUBLIC SDL2::SDL2 SDL2::SDL2main sgl)

install(TARGETS sgl_sdl sgl_sdl_main
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)

install(FILES ${SGL_SDL_PUBLIC_HEADER_FILES} DESTINATION include/sgl/sdl)
