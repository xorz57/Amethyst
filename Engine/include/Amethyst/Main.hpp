#pragma once

#include "PrecompiledHeader.hpp"

#include "Amethyst/Application.hpp"
#include "Amethyst/Logging.hpp"

namespace Amethyst {
    std::unique_ptr<Application> CreateApplication();
}// namespace Amethyst

int main() {
    using namespace Amethyst;
    Logging::Init();
    std::unique_ptr<Application> application = CreateApplication();
    application->Run();
    return EXIT_SUCCESS;
}
