cmake_minimum_required(VERSION 3.5)

project(Searcher_App)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/main.cpp
    src/Line_Words.cpp
    src/Searchers.cpp
)

set(HEADERS
    include/Searchers.h        
    include/Line_Words.h
)

add_executable(searcher_app ${SOURCES})

target_include_directories(searcher_app PUBLIC include)

set(TEST_SOURCES
    tests/Tests.cpp
    src/Line_Words.cpp
    src/Searchers.cpp
)

add_executable(tests ${TEST_SOURCES})

add_test(NAME tests COMMAND tests)

target_include_directories(tests PRIVATE include)
