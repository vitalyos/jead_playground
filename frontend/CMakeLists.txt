project (frontend)
cmake_minimum_required(VERSION 2.8)
add_definitions(-std=c++11 -W -Wall)
file (GLOB HEADERS
   "/inc/*.hpp"
)
file (GLOB SOURCES
   "src/*.cpp"
)

include_directories("/inc" ${GLOG_INCLUDE_DIR} ${BACKEND_INCLUDE_DIRS} ${CURLCPP_SOURCE_DIR}/include ${jsoncpp_SOURCE_DIR}/include ${BACKEND_INCLUDE_DIRS})

add_executable(run ${HEADERS} ${SOURCES})
target_link_libraries (run glog backend curlcpp ${LIB_DIR}/jsoncpp/src/lib_json/libjsoncpp.a fruit)
