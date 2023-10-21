#include "Sandbox/Sandbox.hpp"
#include "Sandbox/SandboxLayer.hpp"

Sandbox::Sandbox(const Amethyst::ApplicationSettings &applicationSettings) : Amethyst::Application(applicationSettings) {
    PushLayer(std::make_unique<SandboxLayer>("SandboxLayer"));
}

std::unique_ptr<Amethyst::Application> Amethyst::CreateApplication() {
    Amethyst::ApplicationSettings applicationSettings;
    applicationSettings.width = 800;
    applicationSettings.height = 600;
    applicationSettings.title = "Sandbox";
    return std::make_unique<Sandbox>(applicationSettings);
}
