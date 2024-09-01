set(SOURCE_FILES
        model/model.h model/model.cpp
        game_loop.cpp game_loop.h
        game_manager.cpp game_manager.h

        graphics_scene.cpp graphics_scene.h
        coordinates.h coordinates.cpp
        config_prod.cpp config_prod.h
        model/custom_graphics_item.cpp model/custom_graphics_item.cpp
        model/paddle.h model/paddle.cpp
        model/ball.h model/ball.cpp
        model/brick.h model/brick.cpp
        model/game_state_manager.h model/game_state_manager.cpp
        model/direction.h model/direction.cpp
        model/game_result_manager.h model/game_result_manager.cpp
        model/bricks_container.cpp model/bricks_container.h
        model/brick_factory.cpp model/brick_factory.h
        log_manager.h
        collision_detectors.cpp collision_detectors.h
        id_generator.h)

# Create the backend library
add_library(lib${PROJECT_NAME}Backend ${SOURCE_FILES})

# Include current directory for backend library
target_include_directories(lib${PROJECT_NAME}Backend PUBLIC .)

# Link Qt Core library to backend
target_link_libraries(lib${PROJECT_NAME}Backend PRIVATE spdlog::spdlog Qt${QT_VERSION_MAJOR}::Gui)
