# Set minimum required CMake version
cmake_minimum_required(VERSION 3.5)

#Start project and set its name to ...
project(ipk-blatt10 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

#Create executable programs

add_executable(test src/test.cc)
add_executable(test2 src/test2.cc)
add_executable(WithPlugins src/withPlugins.cc)