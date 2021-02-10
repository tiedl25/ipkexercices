cmake_minimum_required(VERSION 3.5)

project(ipk-blatt11 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD)

add_executable(main src/main.cc)
add_library(point src/point.cc)
add_library(body src/body.cc)
#add_library(sdlwrapper src/sdlwrapper.cc)

target_link_libraries(main SDL2)
target_link_libraries(main body)
target_link_libraries(main point)
#target_link_libraries(main sdlwrapper)