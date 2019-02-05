cmake_minimum_required(VERSION 3.0.2)

project(lua_test)

if(UNIX)
    message("Platform: UNIX")
    add_definitions("-DUBUNTU1604")
elseif(MINGW)
    message("Platform: MINGW")
    add_definitions("-DMINGW")
endif()



add_executable(${PROJECT_NAME} "main.cpp")

if(UNIX)
    target_link_libraries(${PROJECT_NAME} lua5.3-c++)
elseif(MINGW)
    target_link_libraries(${PROJECT_NAME} lua)
endif()


