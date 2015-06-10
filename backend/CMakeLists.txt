project (backend)
cmake_minimum_required(VERSION 2.8)
add_definitions(-std=c++11 -W -Wall)
include(ExternalProject)

file (GLOB HEADERS
   "model/inc/*.hpp"
)
file (GLOB SOURCES
   "model/src/*.cpp"
)

INCLUDE_DIRECTORIES(${CURLCPP_SOURCE_DIR}/include)

#set (CURLCPP_INCLUDE_DIR ${LIB_DIR}/curlcpp/include/)
#set (CURLCPP_LIB ${LIB_DIR}/curlcpp/src/lib_json/libhiberlite.a)

set(BACKEND_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/model/inc PARENT_SCOPE)

include_directories(
   "model/inc"
   "repository/inc"
   ${FRUIT_INCLUDE_DIR}
   ${GLOG_INCLUDE_DIR}
)

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

add_dependencies(${PROJECT_NAME} fruit glog)

target_link_libraries(${PROJECT_NAME}
    ${GLOG_LIB}
    ${FRUIT_LIB}
    ${SQLITE3_LIB}
)
