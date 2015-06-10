project (backend)
cmake_minimum_required(VERSION 2.8)
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


set (HIBERLATE_INCLUDE_DIR ${LIB_DIR}/hiberlite/include/)
set (HIBERLATE_LIB ${LIB_DIR}/hiberlite/libhiberlite.a)
include_directories(
   "model/inc"
   "repository/inc"
   ${FRUIT_INCLUDE_DIR}
   ${GLOG_INCLUDE_DIR}
   ${HIBERLATE_INCLUDE_DIR}
)

ExternalProject_Add(hiberlite
  SOURCE_DIR ${LIB_DIR}/hiberlite
  GIT_REPOSITORY git@github.com:paulftw/hiberlite.git
  CONFIGURE_COMMAND ""
  BUILD_IN_SOURCE 1
  BUILD_COMMAND make libhiberlite.a
  INSTALL_COMMAND ""
  )

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

add_dependencies(${PROJECT_NAME} hiberlite fruit glog)

target_link_libraries(${PROJECT_NAME}
    ${GLOG_LIB}
    ${HIBERLATE_LIB}
    ${FRUIT_LIB}
)
