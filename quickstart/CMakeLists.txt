add_executable(quickstart main.c)

# Link the lvgl dependency
target_link_libraries(quickstart PRIVATE lvgl::lvgl)
# Get the parent directory of the LVGL source directory
get_filename_component(lvgl_parent_dir "${lvgl_SOURCE_DIR}" DIRECTORY)
# Set include directory for quickstart
target_include_directories(quickstart PRIVATE ${lvgl_parent_dir})
# add include path for lv_conf.h
target_include_directories(lvgl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
