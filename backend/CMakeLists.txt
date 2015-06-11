project (backend)
cmake_minimum_required(VERSION 2.8)
add_definitions(-std=c++11 -W -Wall)
include(ExternalProject)

file (GLOB HEADERS "inc/*.hpp")
file (GLOB SOURCES "src/*.cpp")

include_directories ("inc" ${CURLCPP_SOURCE_DIR}/include ${jsoncpp_SOURCE_DIR}/include ${FRUIT_SOURCE_DIR}/include)
set(BACKEND_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/inc PARENT_SCOPE)

#set(BACKEND_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/model/inc PARENT_SCOPE)

include_directories("model/inc" "repository/inc"
#   ${FRUIT_INCLUDE_DIR}
#   ${GLOG_INCLUDE_DIR}
)

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    glog
    curlcpp
    ${LIB_DIR}/jsoncpp/src/lib_json/libjsoncpp.a
    fruit
)
