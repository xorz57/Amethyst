cmake_minimum_required(VERSION 3.26)

project(Editor)

set(SOURCES src/Application.cpp
            src/Layer.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
add_executable(Amethyst::Editor ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

target_link_libraries(${PROJECT_NAME} PRIVATE Amethyst::Engine)
