#include "Editor/EditorLayer.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#define IMGUI_DEFINE_MATH_OPERATORS
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <implot.h>

EditorLayer::EditorLayer(std::string name) : Amethyst::Layer(std::move(name)) {}

void EditorLayer::OnAttach() {
    // ...
}

void EditorLayer::OnDetach() {
    // ...
}

void EditorLayer::OnFixedUpdate(double dt) {
    // ...
}

void EditorLayer::OnUpdate(double dt) {
    // ...
}

void EditorLayer::OnLateUpdate(double dt) {
    // ...
}
