#include "Sandbox/Application.hpp"
#include "Sandbox/Layer.hpp"

using namespace Amethyst::Sandbox;

Application::Application(const Amethyst::ApplicationSettings &applicationSettings) : Amethyst::Application(applicationSettings) {
    PushLayer(std::make_unique<Layer>("Layer"));
}

std::unique_ptr<Amethyst::Application> Amethyst::CreateApplication() {
    Amethyst::ApplicationSettings applicationSettings;
    applicationSettings.width = 800;
    applicationSettings.height = 600;
    applicationSettings.title = "Sandbox";
    return std::make_unique<Application>(applicationSettings);
}
