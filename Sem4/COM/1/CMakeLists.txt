cmake_minimum_required(VERSION 3.17)
project(1)

set(CMAKE_CXX_STANDARD 20)

add_executable(1 main.cpp serv.cpp serv.h iserv.h serv2.cpp serv2.h iserv2.h IUnknown.cpp IUnknown.h ServerFactory.cpp ServerFactory.h IClassFactory.h ClientServerWrapper.cpp ClientServerWrapper.h)