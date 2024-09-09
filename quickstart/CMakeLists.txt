add_executable(quickstart main.c)

# Link the lvgl dependency
target_link_libraries(quickstart PRIVATE lvgl::lvgl)
# Set include directory of the third party lib for quickstart
target_include_directories(quickstart PRIVATE ${THIRD_PARTY_DIR})
# add include path for lv_conf.h
target_include_directories(lvgl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
