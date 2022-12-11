# Look for SFML >= 2.0, with the specific subcomponents listed below
find_package(SFML 2 COMPONENTS system window graphics)

# Add include dirs for SFML
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

add_library(game Game.cpp Game.h)
target_include_directories(game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link target to SFML libs
TARGET_LINK_LIBRARIES(game sfml-system sfml-graphics sfml-window)

# Install our executable to the CMAKE_INSTALL_PREFIX/bin
INSTALL(TARGETS game DESTINATION bin)