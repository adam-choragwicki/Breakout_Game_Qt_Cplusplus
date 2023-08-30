set(SOURCE_FILES
        main_window.cpp main_window.h
        main_window.h main_window.cpp
        gui_config.h)

add_library(lib${PROJECT_NAME}Frontend ${SOURCE_FILES})
target_include_directories(lib${PROJECT_NAME}Frontend PUBLIC ${BACKEND_DIR})
target_link_libraries(lib${PROJECT_NAME}Frontend PUBLIC Qt${QT_VERSION_MAJOR}::Widgets)
