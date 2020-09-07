cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall -j32")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SDL2Tutorial)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

INCLUDE(FindPkgConfig)

find_package(SDL2 REQUIRED)
PKG_SEARCH_MODULE(SDL2_IMAGE REQUIRED SDL2_image>=2.0.0)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} src)

file(GLOB project_SRC "src/*.cpp")
add_executable(RpgTutorial ${project_SRC})
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(RpgTutorial ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})