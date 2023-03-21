cmake_minimum_required(VERSION 3.24)
project(spinal_code)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(spinal_code
        include/spookyhash.h
        src/spookyhash.cpp
        src/main.cpp
        include/encoder.h include/RNG.h src/RNG.cpp include/source.h src/encoder.cpp)
