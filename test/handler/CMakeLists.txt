cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(handler_test VERSION 1.0.0)
add_executable(handler_test main.c)

add_test(NAME HandlerTest COMMAND handler_test)

