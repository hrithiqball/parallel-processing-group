cmake_minimum_required(VERSION 3.31)
project(parallel_processing_group)

set(CMAKE_CXX_STANDARD 20)

find_package(MPI REQUIRED)
include_directories(${MPI_CXX_INCLUDE_PATH})

add_executable(main-multithread main-multithread.cpp)
target_link_libraries(main-multithread ${MPI_CXX_LIBRARIES})

add_executable(parallel-sorting parallel-sorting.cpp)
target_link_libraries(parallel-sorting ${MPI_CXX_LIBRARIES})

add_executable(main-serial main-serial.cpp)
add_executable(sequential-sorting sequential-sorting.cpp)
