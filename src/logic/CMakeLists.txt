add_library(logic World.cpp World.h AbstractFactory.h Observer.cpp Observer.h Subject.cpp Subject.h EntityModel.cpp EntityModel.h)
target_include_directories(logic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})