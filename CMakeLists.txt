cmake_minimum_required(VERSION 3.20)
project(lee_lang)

set(CMAKE_CXX_STANDARD 17)

add_executable(leepls src/main.cpp src/includes/Compiler/Compiler.cpp src/includes/Compiler/Compiler.hpp src/includes/Base/opcodes.hpp src/includes/VM/VM.cpp src/includes/VM/VM.hpp)
