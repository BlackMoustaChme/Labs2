cmake_minimum_required(VERSION 3.17)
project(1)

set(CMAKE_CXX_STANDARD 20)

add_executable(1 main.cpp servs/serv.cpp servs/serv.h servs/iserv.h servs/serv2.cpp servs/serv2.h servs/iserv2.h dll/IUnknown.cpp headers/IUnknown.h servs/ServerFactory.cpp servs/ServerFactory.h headers/IClassFactory.h servs/ClientServerWrapper.cpp servs/ClientServerWrapper.h headers/IVector.h dll/Vector_.cpp headers/Vector_.h dll/VectorFactory_.cpp headers/VectorFactory_.h dll/ClientVectorWrapper.cpp headers/ClientVectorWrapper.h dll/Client.cpp ManagerDLL.cpp ManagerDLL.h ModuleInfo.h)