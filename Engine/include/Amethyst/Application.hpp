#pragma once

#include "PCH.hpp"

#include "Amethyst/ApplicationSettings.hpp"
#include "Amethyst/LayerStack.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Amethyst {
    class Application {
    public:
        explicit Application(ApplicationSettings applicationSettings);
        virtual ~Application();

        void PushLayer(std::unique_ptr<Layer> layer);
        void PopLayer();
        void Run();

    private:
        ApplicationSettings mApplicationSettings;
        LayerStack mLayerStack;
        GLFWwindow *mWindow = nullptr;
    };
}// namespace Amethyst
