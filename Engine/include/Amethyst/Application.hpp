#pragma once

#include "PCH.hpp"

#include "Amethyst/ApplicationSettings.hpp"
#include "Amethyst/LayerStack.hpp"

namespace Amethyst {
    class Application {
    public:
        explicit Application(ApplicationSettings applicationSettings);
        virtual ~Application() = default;
        void PushLayer(std::unique_ptr<Layer> layer);
        void PopLayer();
        void Run();

    private:
        ApplicationSettings mApplicationSettings;
        LayerStack mLayerStack;
    };
}// namespace Amethyst
