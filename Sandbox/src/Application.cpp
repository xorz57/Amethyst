#include "Sandbox/Application.hpp"
#include "Sandbox/Layer.hpp"

using namespace Amethyst::Sandbox;

Application::Application(const Amethyst::Engine::ApplicationSettings &applicationSettings) : Amethyst::Engine::Application(applicationSettings) {
    PushLayer(std::make_unique<Layer>("Layer"));
}

std::unique_ptr<Amethyst::Engine::Application> Amethyst::Engine::CreateApplication() {
    Amethyst::Engine::ApplicationSettings applicationSettings;
    applicationSettings.width = 800;
    applicationSettings.height = 600;
    applicationSettings.title = "Sandbox";
    return std::make_unique<Application>(applicationSettings);
}
