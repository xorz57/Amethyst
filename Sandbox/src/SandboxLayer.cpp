#include "Sandbox/SandboxLayer.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#define IMGUI_DEFINE_MATH_OPERATORS
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <implot.h>

SandboxLayer::SandboxLayer(std::string name) : Amethyst::Layer(std::move(name)) {}

void SandboxLayer::OnAttach() {
    // ...
}

void SandboxLayer::OnDetach() {
    // ...
}

void SandboxLayer::OnFixedUpdate(double dt) {
    // ...
}

void SandboxLayer::OnUpdate(double dt) {
    // ...
}
