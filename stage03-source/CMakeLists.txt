cmake_minimum_required(VERSION 3.16)

project(stage03_source LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(stage03_source
  src/main.cpp
  src/source.cpp
)
