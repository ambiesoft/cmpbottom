cmake_minimum_required(VERSION 3.5)

project(cmpbottom LANGUAGES C)

add_executable(cmpbottom main.c)

install(TARGETS cmpbottom
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
