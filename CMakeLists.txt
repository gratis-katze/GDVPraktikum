cmake_minimum_required(VERSION 3.22)
project(GDV)

set(CMAKE_CXX_STANDARD 14)

add_executable(GDV main.cpp teil_1.cpp Wuerfel.cpp Wuerfel.h Robot.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -framework GLUT -framework OpenGL") # compiler version and compiler flags.

set(SOURCE_FILES main.cpp) # which files should be compiled

add_executable(untitled ${SOURCE_FILES}) # which files should produce executables
