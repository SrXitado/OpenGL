cmake_minimum_required(VERSION 3.20)

project(opengl)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(opengl 
    main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/glad.c
 )

target_include_directories(opengl PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../dependencies
)

target_link_libraries(opengl PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/glfw/glfw3.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/glfw/glfw3.lib
)

if(MSVC)
    target_link_options(opengl PRIVATE
        "$<$<CONFIG:Debug>:/NODEFAULTLIB:MSVCRT>")
endif()