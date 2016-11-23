cmake_minimum_required (VERSION 3.5.1)
project(Stack)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
set(IMPLEMENTATION
	Stack.hpp
	Stack.cpp
)

source_group("src" FILES ${IMPLEMENTATION})
add_executable(${PROJECT_NAME} 
	Main.cpp
	${IMPLEMENTATION}
)
