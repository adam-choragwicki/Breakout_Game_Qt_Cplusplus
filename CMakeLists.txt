cmake_minimum_required(VERSION 3.10)

project(Breakout LANGUAGES CXX)

set(QT_VERSION_MAJOR 6)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(PROJECT_ROOT ${CMAKE_SOURCE_DIR})

set(INCLUDES_DIR ${PROJECT_ROOT}/inc)
set(SOURCES_DIR ${PROJECT_ROOT}/src)
set(UI_FORMS_DIR ${PROJECT_ROOT}/ui_forms)
set(RESOURCE_FILES_DIR ${PROJECT_ROOT}/resource_files)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${UI_FORMS_DIR})

find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(SOURCE_FILES
        ${INCLUDES_DIR}/breakout.h ${SOURCES_DIR}/breakout.cpp
        ${INCLUDES_DIR}/view/main_window.h ${SOURCES_DIR}/view/main_window.cpp
        ${INCLUDES_DIR}/controller.h ${SOURCES_DIR}/controller.cpp
        ${INCLUDES_DIR}/model/model.h ${SOURCES_DIR}/model/model.cpp
        ${INCLUDES_DIR}/breakout.h ${SOURCES_DIR}/breakout.cpp
        ${INCLUDES_DIR}/model/model.h ${SOURCES_DIR}/model/model.cpp
        ${INCLUDES_DIR}/model/paddle.h ${SOURCES_DIR}/model/paddle.cpp
        ${INCLUDES_DIR}/model/ball.h ${SOURCES_DIR}/model/ball.cpp
        ${INCLUDES_DIR}/model/brick.h ${SOURCES_DIR}/model/brick.cpp inc/common.h
        ${INCLUDES_DIR}/log_manager.h)

add_library(libBreakout ${SOURCE_FILES})
target_include_directories(libBreakout PUBLIC ${INCLUDES_DIR})
target_link_libraries(libBreakout Qt${QT_VERSION_MAJOR}::Widgets)

add_executable(Breakout WIN32 ${SOURCES_DIR}/main.cpp)
target_link_libraries(Breakout libBreakout)

if (WIN32)
    set_target_properties(Breakout PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_ROOT}/executable_windows)
elseif (UNIX)
    set_target_properties(Breakout PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_ROOT}/executable_linux)
endif (WIN32)
