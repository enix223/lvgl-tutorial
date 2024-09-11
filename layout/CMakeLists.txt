add_executable(layout main.cpp)

# Link the lvgl dependency
target_link_libraries(layout PRIVATE lvgl::lvgl)

# Set include directory of the third party lib for layout
target_include_directories(layout PRIVATE ${THIRD_PARTY_DIR})

# add include path for lv_conf.h
target_include_directories(lvgl PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
