cmake_minimum_required(VERSION 3.0)

project(TextEditor)

# Добавляем исполняемый файл main.cpp
add_executable(TextEditor main.cpp)

# Добавляем директорию include в список директорий для поиска заголовочных файлов
include_directories(include)

# Добавляем два заголовочных файла в проект
set(SOURCES include/parser.h include/operations.h)

# Добавляем их в качестве зависимостей для исполняемого файла
target_sources(TextEditor PRIVATE ${SOURCES})
