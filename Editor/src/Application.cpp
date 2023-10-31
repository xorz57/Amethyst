#include "Editor/Application.hpp"
#include "Editor/Layer.hpp"

using namespace Amethyst::Editor;

Application::Application(const Amethyst::ApplicationSettings &applicationSettings) : Amethyst::Application(applicationSettings) {
    PushLayer(std::make_unique<Layer>("Layer"));
}

std::unique_ptr<Amethyst::Application> Amethyst::CreateApplication() {
    Amethyst::ApplicationSettings applicationSettings;
    applicationSettings.width = 800;
    applicationSettings.height = 600;
    applicationSettings.title = "Editor";
    return std::make_unique<Application>(applicationSettings);
}
