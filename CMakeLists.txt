project (jead_playground)
cmake_minimum_required(VERSION 2.8)

include(ExternalProject)

set (LIB_DIR ${CMAKE_CURRENT_BINARY_DIR}/lib)
set (GLOG_INCLUDE_DIR ${LIB_DIR}/glog/include/)
set (FRUIT_INCLUDE_DIR ${LIB_DIR}/fruit/include/)
set (GLOG_LIB ${LIB_DIR}/glog/lib/libglog.so)
set (FRUIT_LIB ${LIB_DIR}/fruit/lib/libfruit.so)

add_subdirectory(backend)
add_subdirectory(frontend)

ExternalProject_Add(glog
  SOURCE_DIR ${LIB_DIR}/glog
  GIT_REPOSITORY git@github.com:google/glog.git
  CONFIGURE_COMMAND ${LIB_DIR}/glog/configure --prefix=${LIB_DIR}/glog
  BUILD_IN_SOURCE 1
  BUILD_COMMAND make
  INSTALL_COMMAND make install
)

ExternalProject_Add(fruit
  SOURCE_DIR ${LIB_DIR}/fruit
  GIT_REPOSITORY git@github.com:google/fruit.git
  CONFIGURE_COMMAND cmake ${LIB_DIR}/fruit -DCMAKE_INSTALL_PREFIX=${LIB_DIR}/fruit
  BUILD_IN_SOURCE 1
  BUILD_COMMAND make
  INSTALL_COMMAND make install
)
