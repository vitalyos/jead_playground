project (backend)
cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++11 -W -Wall)

file (GLOB HEADERS "model/inc/*.hpp")
file (GLOB SOURCES "model/src/*.cpp")

include_directories("model/inc")

add_library(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT_NAME} glog fruit odb odb-sqlite)
