project (backend)
cmake_minimum_required(VERSION 3.1)
add_definitions(-std=c++11 -W -Wall)
include(ExternalProject)

file (GLOB HEADERS
   "model/inc/*.hpp"
   "repository/inc/*.hpp"
)
file (GLOB SOURCES
   "model/src/*.cpp"
   "repository/inc/*.hpp"
)

include_directories("model/inc" "repository/inc")
set (LIB_DIR ${CMAKE_CURRENT_BINARY_DIR}/../lib)
# add hiberlit

ExternalProject_Add(hiberlite
  SOURCE_DIR ${LIB_DIR}/hiberlite
  GIT_REPOSITORY git@github.com:paulftw/hiberlite.git
  CONFIGURE_COMMAND ""
  BUILD_IN_SOURCE 1
  BUILD_COMMAND make libhiberlite.a
  INSTALL_COMMAND ""
  )
include_directories(${LIB_DIR}/hiberlite/include/)


add_library(${PROJECT_NAME} ${HEADERS} ${SOURCES})
add_dependencies(${PROJECT_NAME} hiberlite)
target_link_libraries(${PROJECT_NAME} glog fruit  ${LIB_DIR}/hiberlite/libhiberlite.a)
