cmake_minimum_required(VERSION 3.5)

project(Searcher_App)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCES 
    EN_Titles.cpp
    EN_Titles.h
    Episode_Search.cpp
    Episode_Search.h
    Line_Words.cpp
    Line_Words.h
    main.cpp
    RU_Titles.cpp
    RU_Titles.h
    Series_Search.cpp
    Series_Search.h    
)

add_executable(episode_searcher ${SOURCES})

