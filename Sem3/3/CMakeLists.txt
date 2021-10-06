cmake_minimum_required(VERSION 3.17)
project(3)

set(CMAKE_CXX_STANDARD 20)

add_executable(3 main.cpp Datetime.h DLList.h App.h UI.h DataObtaining.h App.cpp Datetime.cpp DLList.cpp UI.cpp DataObtaining.cpp)