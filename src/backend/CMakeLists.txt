set(SOURCE_FILES
        model/model.h model/model.cpp
        model/paddle.h model/paddle.cpp
        model/ball.h model/ball.cpp
        model/brick.h model/brick.cpp
        model/game_state_manager.h model/game_state_manager.cpp
        model/direction.h model/direction.cpp
        model/game_result_manager.h model/game_result_manager.cpp
        model/bricks_container.cpp model/bricks_container.h
        model/brick_factory.cpp model/brick_factory.h
        config.h
        log_manager.h
        collision_detectors.cpp collision_detectors.h)

add_library(lib${PROJECT_NAME}Backend ${SOURCE_FILES})
target_include_directories(lib${PROJECT_NAME}Backend PUBLIC .)
target_link_libraries(lib${PROJECT_NAME}Backend PUBLIC Qt${QT_VERSION_MAJOR}::Gui)
