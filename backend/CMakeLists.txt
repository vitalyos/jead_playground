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

ExternalProject_Add(fruit
  SOURCE_DIR ${LIB_DIR}/fruit
  GIT_REPOSITORY git@github.com:google/fruit.git
  CONFIGURE_COMMAND cmake ${LIB_DIR}/fruit
  BUILD_IN_SOURCE 1
  BUILD_COMMAND make
  INSTALL_COMMAND ""
  )

ExternalProject_Add(glog
  SOURCE_DIR ${LIB_DIR}/glog
  GIT_REPOSITORY git@github.com:google/glog.git
  CONFIGURE_COMMAND ${LIB_DIR}/glog/configure
  BUILD_IN_SOURCE 1
  BUILD_COMMAND make
  INSTALL_COMMAND ""
  )
include_directories(${LIB_DIR}/hiberlite/include/)
include_directories(${LIB_DIR}/glog/include/)
include_directories(${LIB_DIR}/fruit/include/)

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})
add_dependencies(${PROJECT_NAME} hiberlite)
add_dependencies(${PROJECT_NAME} fruit)
add_dependencies(${PROJECT_NAME} glog)
target_link_libraries(${PROJECT_NAME}
    ${LIB_DIR}/glog/libglog.a
    ${LIB_DIR}/hiberlite/libhiberlite.a
    ${LIB_DIR}/fruit/src/libfruit.so
)
