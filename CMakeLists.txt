# Set minimum required CMake version
cmake_minimum_required(VERSION 3.5)

# Start project and set its name to ipk-demo
project(ipk-blatt07/1 LANGUAGES CXX)

# Force compiler to run in C++14 mode
set(CMAKE_CXX_STANDARD 14)

# Create executable programs
add_library(lib src/canvas.cc src/include/canvas.hh src/point.cc src/include/point.hh src/pgm.cc src/include/pgm.hh)

add_executable(main src/main.cc src/IterationResult.cc src/include/IterationResult.hh)

target_link_libraries(main PRIVATE lib)