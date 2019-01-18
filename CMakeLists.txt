cmake_minimum_required(VERSION 3.0.2)

project(lua_test)

add_executable(${PROJECT_NAME} "main.cpp")
target_link_libraries(${PROJECT_NAME} lua5.3-c++)