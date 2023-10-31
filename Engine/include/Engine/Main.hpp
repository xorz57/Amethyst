#pragma once

#include "PCH.hpp"

#include "Engine/Application.hpp"
#include "Engine/Logging.hpp"

namespace Amethyst::Engine {
    std::unique_ptr<Application> CreateApplication();
}// namespace Amethyst::Engine

int main() {
    using namespace Amethyst::Engine;
    Logging::Init();
    std::unique_ptr<Application> application = CreateApplication();
    application->Run();
    return EXIT_SUCCESS;
}
