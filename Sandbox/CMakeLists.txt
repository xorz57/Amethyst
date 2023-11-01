cmake_minimum_required(VERSION 3.26)

project(Sandbox)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()

set(SOURCES src/Application.cpp
            src/Layer.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
add_executable(Amethyst::Sandbox ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PRIVATE Amethyst::Engine)
