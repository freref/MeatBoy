add_library(logic Camera.cpp Camera.h Stopwatch.cpp Stopwatch.h World.cpp World.h)
target_include_directories(logic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})