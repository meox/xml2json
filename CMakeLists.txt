cmake_minimum_required(VERSION 3.6)
project(xml2json)

set(CMAKE_CXX_STANDARD 14)

include_directories(Include)


set(SOURCE_FILES main.cpp pugixml.cpp)
add_executable(xml2json ${SOURCE_FILES})