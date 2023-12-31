#pragma once

#include "PCH.hpp"

namespace Amethyst::Engine {
    struct ApplicationSettings {
        int width = 800;
        int height = 600;
        std::string title = "Application";
        double fixedDeltaTime = 1.0 / 50.0;
    };
}// namespace Amethyst::Engine
