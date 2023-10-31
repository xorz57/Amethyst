#pragma once

#include "PCH.hpp"

#include "Amethyst/ApplicationSettings.hpp"
#include "Amethyst/LayerStack.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Amethyst::Engine {
    class Application {
    public:
        explicit Application(ApplicationSettings applicationSettings);
        virtual ~Application();

        Application &operator=(const Application &other) = delete;
        Application &operator=(Application &&other) = delete;

        void PushLayer(std::unique_ptr<Layer> layer);
        void PopLayer();
        void Run();

    private:
        ApplicationSettings mApplicationSettings;
        LayerStack mLayerStack;
        GLFWwindow *mWindow = nullptr;
    };
}// namespace Amethyst::Engine
