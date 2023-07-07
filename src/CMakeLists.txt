add_library(sgl)

target_sources(sgl PRIVATE
        version.cpp
)


target_sources(sgl PUBLIC "${SGL_PUBLIC_HEADER_FILES}")
target_compile_features(sgl PUBLIC "cxx_std_${SGL_CXX_STANDARD}")
target_include_directories(sgl PUBLIC ../include)

file(GLOB_RECURSE SGL_PUBLIC_HEADER_FILES
    "${PROJECT_SOURCE_DIR}/include/sgl/*.h"
)


install(TARGETS sgl
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)

install(FILES ${SGL_PUBLIC_HEADER_FILES} DESTINATION include/sgl)

if (${SGL_BACKEND_SDL})
    add_subdirectory(sdl)
endif()
