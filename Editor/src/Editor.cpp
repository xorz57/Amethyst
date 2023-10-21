#include "Editor/Editor.hpp"
#include "Editor/EditorLayer.hpp"

Editor::Editor(const Amethyst::ApplicationSettings &applicationSettings) : Amethyst::Application(applicationSettings) {
    PushLayer(std::make_unique<EditorLayer>("EditorLayer"));
}

std::unique_ptr<Amethyst::Application> Amethyst::CreateApplication() {
    Amethyst::ApplicationSettings applicationSettings;
    applicationSettings.width = 800;
    applicationSettings.height = 600;
    applicationSettings.title = "Editor";
    return std::make_unique<Editor>(applicationSettings);
}
