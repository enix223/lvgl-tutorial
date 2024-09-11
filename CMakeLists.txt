cmake_minimum_required(VERSION 3.12.4)
project(lvgl-tutorial VERSION 0.1.0 LANGUAGES C CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# third party repo dir
set(THIRD_PARTY_DIR ${CMAKE_BINARY_DIR}/deps)

include(FetchContent)

################################
#         lvgl dependency      #
################################
FetchContent_Declare(
    lvgl
    GIT_REPOSITORY git@github.com:lvgl/lvgl.git
    GIT_TAG        v9.2.0
    SOURCE_DIR     deps/lvgl
)
FetchContent_MakeAvailable(lvgl)

add_subdirectory(quickstart)
add_subdirectory(layout)

include(CTest)
enable_testing()
