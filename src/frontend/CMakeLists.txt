set(SOURCE_FILES
        main_window.cpp main_window.h
        gui_config.h)

#add_library(lib${PROJECT_NAME}Frontend ${SOURCE_FILES})
#target_include_directories(lib${PROJECT_NAME}Frontend PUBLIC ${BACKEND_DIR})
#target_link_libraries(lib${PROJECT_NAME}Frontend PUBLIC Qt${QT_VERSION_MAJOR}::Widgets)

# Create the frontend library
add_library(lib${PROJECT_NAME}Frontend ${SOURCE_FILES})

# Include directories for frontend
target_include_directories(lib${PROJECT_NAME}Frontend PUBLIC . ${BACKEND_DIR})

# Link spdlog and Qt Widgets to frontend
target_link_libraries(lib${PROJECT_NAME}Frontend PUBLIC spdlog::spdlog Qt${QT_VERSION_MAJOR}::Widgets)
