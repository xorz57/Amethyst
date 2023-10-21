#pragma once

#include "PrecompiledHeader.hpp"

namespace Amethyst {
    struct ApplicationSettings {
        int width = 0;
        int height = 0;
        std::string title = "Application";
        double fixedDeltaTime = 1.0 / 50.0;
        double maxDeltaTime = 1.0 / 10.0;
        double timeScale = 1.0;
    };
}// namespace Amethyst
