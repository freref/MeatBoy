find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_library(game Game.cpp Game.h ConcreteFactory.cpp ConcreteFactory.h StateManager.cpp StateManager.h State.cpp State.h LevelState.cpp LevelState.h MenuState.cpp MenuState.h)

target_link_libraries(game sfml-graphics)
target_include_directories(game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${SFML_INCLUDE_DIR})