#pragma once

#include "PCH.hpp"

#include <spdlog/spdlog.h>

namespace Amethyst {
    class Logging {
    public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger> &GetEngineLogger() { return sEngineLogger; }
        inline static std::shared_ptr<spdlog::logger> &GetApplicationLogger() { return sApplicationLogger; }

    private:
        static std::shared_ptr<spdlog::logger> sEngineLogger;
        static std::shared_ptr<spdlog::logger> sApplicationLogger;
    };
}// namespace Amethyst

#define ENGINE_TRACE(...) Amethyst::Logging::GetEngineLogger()->trace(__VA_ARGS__)
#define ENGINE_INFO(...) Amethyst::Logging::GetEngineLogger()->info(__VA_ARGS__)
#define ENGINE_WARN(...) Amethyst::Logging::GetEngineLogger()->warn(__VA_ARGS__)
#define ENGINE_ERROR(...) Amethyst::Logging::GetEngineLogger()->error(__VA_ARGS__)

#define APPLICATION_TRACE(...) Amethyst::Logging::GetApplicationLogger()->trace(__VA_ARGS__)
#define APPLICATION_INFO(...) Amethyst::Logging::GetApplicationLogger()->info(__VA_ARGS__)
#define APPLICATION_WARN(...) Amethyst::Logging::GetApplicationLogger()->warn(__VA_ARGS__)
#define APPLICATION_ERROR(...) Amethyst::Logging::GetApplicationLogger()->error(__VA_ARGS__)
