cmake_minimum_required(VERSION 2.9)
project(AStarPathPlanning)

set(CMAKE_CXX_STANDARD 11)

include_directories(include/)

add_executable(AStarPathPlanning
        src/main.cpp
        src/jsoncpp.cpp
        include/AStarSearch.h
        include/Utils.h
        include/json/json.h
        include/json/json-forwards.h)