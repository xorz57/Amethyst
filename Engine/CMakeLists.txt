cmake_minimum_required(VERSION 3.26)

project(Engine)

set(CMAKE_CXX_STANDARD 20)

find_package(spdlog REQUIRED)
find_package(glm REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glad REQUIRED)
find_package(imgui REQUIRED)
find_package(implot REQUIRED)
find_package(EnTT REQUIRED)
find_package(box2d REQUIRED)

set(SOURCES src/Application.cpp
            src/Layer.cpp
            src/LayerStack.cpp
            src/Logging.cpp
            src/Shader.cpp)

add_library(${PROJECT_NAME} ${SOURCES})
add_library(Amethyst::Engine ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_precompile_headers(${PROJECT_NAME} PRIVATE include/PCH.hpp)

target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)
target_link_libraries(${PROJECT_NAME} PUBLIC glm::glm)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC glad::glad)
target_link_libraries(${PROJECT_NAME} PUBLIC imgui::imgui)
target_link_libraries(${PROJECT_NAME} PUBLIC implot::implot)
target_link_libraries(${PROJECT_NAME} PRIVATE EnTT::EnTT)
target_link_libraries(${PROJECT_NAME} PRIVATE box2d::box2d)
