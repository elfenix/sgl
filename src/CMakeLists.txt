add_library(sgl)

target_sources(sgl PRIVATE
        application.cpp
        null_state_storage.cpp
        state_storage.cpp
        state_storage_heap.cpp
        version.cpp
)

file(GLOB SGL_PUBLIC_HEADER_FILES "${PROJECT_SOURCE_DIR}/include/sgl/*.h")
file(GLOB SGL_CPP_PUBLIC_HEADER_FILES "${PROJECT_SOURCE_DIR}/include/sgl/cpp/*.h")
file(GLOB SGL_DETAIL_PUBLIC_HEADER_FILES "${PROJECT_SOURCE_DIR}/include/sgl/detail/*.h")
file(GLOB SGL_EVENTS_PUBLIC_HEADER_FILES "${PROJECT_SOURCE_DIR}/include/sgl/events/*.h")
file(GLOB SGL_INPUT_PUBLIC_HEADER_FILES "${PROJECT_SOURCE_DIR}/include/sgl/input/*.h")
file(GLOB SGL_PLATFORM_PUBLIC_HEADER_FILES "${PROJECT_SOURCE_DIR}/include/sgl/platform/*.h")

target_sources(sgl PUBLIC 
    "${SGL_PUBLIC_HEADER_FILES}" 
    "${SGL_CPP_PUBLIC_HEADER_FILES}"
    "${SGL_DETAIL_PUBLIC_HEADER_FILES}"
    "${SGL_EVENTS_PUBLIC_HEADER_FILES}"
    "${SGL_INPUT_PUBLIC_HEADER_FILES}"
    "${SGL_PLATFORM_PUBLIC_HEADER_FILES}"
)

target_compile_features(sgl PUBLIC "cxx_std_${SGL_CXX_STANDARD}")
target_include_directories(sgl PUBLIC ../include)


install(TARGETS sgl
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)

install(FILES ${SGL_PUBLIC_HEADER_FILES} DESTINATION include/sgl)
install(FILES ${SGL_CPP_PUBLIC_HEADER_FILES} DESTINATION include/sgl/cpp)
install(FILES ${SGL_DETAIL_PUBLIC_HEADER_FILES} DESTINATION include/sgl/detail)
install(FILES ${SGL_EVENTS_PUBLIC_HEADER_FILES} DESTINATION include/sgl/events)
install(FILES ${SGL_INPUT_PUBLIC_HEADER_FILES} DESTINATION include/sgl/input)
install(FILES ${SGL_PLATFORM_PUBLIC_HEADER_FILES} DESTINATION include/sgl/platform)

if (${SGL_BACKEND_SDL})
    add_subdirectory(sdl)
endif()
