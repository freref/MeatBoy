add_subdirectory(game)
add_subdirectory(logic)

add_executable(src main.cpp)
target_link_libraries(src game logic)
install(TARGETS src DESTINATION bin)