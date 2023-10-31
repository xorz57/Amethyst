#pragma once

#include "Amethyst/Application.hpp"
#include "Amethyst/Main.hpp"

namespace Amethyst::Sandbox {
    class Application : public Amethyst::Application {
    public:
        explicit Application(const Amethyst::ApplicationSettings &applicationSettings);
    };
}// namespace Amethyst::Sandbox
