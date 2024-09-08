cmake_minimum_required(VERSION 3.12.4)
project(lvgl-tutorial VERSION 0.1.0 LANGUAGES C CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)

################################
#         lvgl dependency      #
################################
FetchContent_Declare(
    lvgl
    GIT_REPOSITORY https://github.com/lvgl/lvgl.git
    GIT_TAG        v9.2.0
)
FetchContent_MakeAvailable(lvgl)

################################
#     quickstart executable    #
################################
add_executable(quickstart quickstart/main.c)
# add include path for quickstart executable
include_directories(${CMAKE_SOURCE_DIR}/quickstart)
target_include_directories(quickstart PRIVATE ${lvgl_SOURCE_DIR}/)
# Link the lvgl dependency
target_link_libraries(quickstart PRIVATE lvgl::lvgl)

include(CTest)
enable_testing()
