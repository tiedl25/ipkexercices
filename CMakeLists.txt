# Set minimum required CMake version
cmake_minimum_required(VERSION 3.5)

# Start project and set its name to ipk-demo
project(ipk-blatt07/1 LANGUAGES CXX)

# Force compiler to run in C++14 mode
set(CMAKE_CXX_STANDARD 14)

# Create executable programs
add_library(lib src/io.cc src/include/io.hh src/include/statistics.hh)

add_executable(statisticsdriver src/statisticsdriver.cc)

target_link_libraries(statisticsdriver PRIVATE lib)


enable_testing()
add_executable(ctest src/ctest.cc src/include/point.hh)
add_test(NAME ctest COMMAND ctest)