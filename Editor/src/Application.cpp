#include "Editor/Application.hpp"
#include "Editor/Layer.hpp"

using namespace Amethyst::Editor;

Application::Application(const Amethyst::Engine::ApplicationSettings &applicationSettings) : Amethyst::Engine::Application(applicationSettings) {
    PushLayer(std::make_unique<Layer>("Layer"));
}

std::unique_ptr<Amethyst::Engine::Application> Amethyst::Engine::CreateApplication() {
    Amethyst::Engine::ApplicationSettings applicationSettings;
    applicationSettings.width = 800;
    applicationSettings.height = 600;
    applicationSettings.title = "Editor";
    return std::make_unique<Application>(applicationSettings);
}
