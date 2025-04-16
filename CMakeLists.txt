cmake_minimum_required(VERSION 3.16)
project(SAMI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Sadece x64 platformunu destekle
if(NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(FATAL_ERROR "SAMI only supports x64 builds on Windows.")
endif()

# Alt projeleri ekle
add_subdirectory(SAMI)
add_subdirectory(SandBox)
