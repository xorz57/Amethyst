#pragma once

#include "Amethyst/Application.hpp"
#include "Amethyst/Main.hpp"

namespace Amethyst::Sandbox {
    class Application : public Amethyst::Engine::Application {
    public:
        explicit Application(const Amethyst::Engine::ApplicationSettings &applicationSettings);
    };
}// namespace Amethyst::Sandbox
