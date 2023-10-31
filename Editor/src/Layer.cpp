#include "Editor/Layer.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#define IMGUI_DEFINE_MATH_OPERATORS
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <implot.h>

using namespace Amethyst::Editor;

Layer::Layer(std::string name) : Amethyst::Engine::Layer(std::move(name)) {}

void Layer::OnAttach() {
    // ...
}

void Layer::OnDetach() {
    // ...
}

void Layer::OnFixedUpdate(double dt) {
    // ...
}

void Layer::OnUpdate(double dt) {
    // ...
}
