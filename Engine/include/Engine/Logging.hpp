#pragma once

#include "PCH.hpp"

#include <spdlog/spdlog.h>

#define ENGINE_TRACE(...) Amethyst::Engine::Logging::GetEngineLogger()->trace(__VA_ARGS__)
#define ENGINE_INFO(...) Amethyst::Engine::Logging::GetEngineLogger()->info(__VA_ARGS__)
#define ENGINE_WARN(...) Amethyst::Engine::Logging::GetEngineLogger()->warn(__VA_ARGS__)
#define ENGINE_ERROR(...) Amethyst::Engine::Logging::GetEngineLogger()->error(__VA_ARGS__)

#define APPLICATION_TRACE(...) Amethyst::Engine::Logging::GetApplicationLogger()->trace(__VA_ARGS__)
#define APPLICATION_INFO(...) Amethyst::Engine::Logging::GetApplicationLogger()->info(__VA_ARGS__)
#define APPLICATION_WARN(...) Amethyst::Engine::Logging::GetApplicationLogger()->warn(__VA_ARGS__)
#define APPLICATION_ERROR(...) Amethyst::Engine::Logging::GetApplicationLogger()->error(__VA_ARGS__)

namespace Amethyst::Engine {
    class Logging {
    public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger> &GetEngineLogger() { return sEngineLogger; }
        inline static std::shared_ptr<spdlog::logger> &GetApplicationLogger() { return sApplicationLogger; }

    private:
        static std::shared_ptr<spdlog::logger> sEngineLogger;
        static std::shared_ptr<spdlog::logger> sApplicationLogger;
    };
}// namespace Amethyst::Engine
