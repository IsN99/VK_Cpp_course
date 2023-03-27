cmake_minimum_required(VERSION 3.5)

project(Searcher_App)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCES     
    Searchers.cpp
    Searchers.h
    Line_Words.cpp
    Line_Words.h
    main.cpp       
)

add_executable(searcher_app ${SOURCES})

