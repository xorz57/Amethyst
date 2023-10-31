#pragma once

#include "Engine/Application.hpp"
#include "Engine/Main.hpp"

namespace Amethyst::Sandbox {
    class Application : public Amethyst::Engine::Application {
    public:
        explicit Application(const Amethyst::Engine::ApplicationSettings &applicationSettings);
    };
}// namespace Amethyst::Sandbox
