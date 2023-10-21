cmake_minimum_required(VERSION 3.26)

project(Editor)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES src/Editor.cpp
            src/EditorLayer.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PRIVATE Engine)