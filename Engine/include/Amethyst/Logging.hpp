#pragma once

#include "PrecompiledHeader.hpp"

#include <spdlog/spdlog.h>

namespace Amethyst {
    class Logging {
    public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger> &GetServerLogger() { return sServerLogger; }
        inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return sClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> sServerLogger;
        static std::shared_ptr<spdlog::logger> sClientLogger;
    };
}// namespace Amethyst

#define SERVER_TRACE(...) Amethyst::Logging::GetServerLogger()->trace(__VA_ARGS__)
#define SERVER_INFO(...) Amethyst::Logging::GetServerLogger()->info(__VA_ARGS__)
#define SERVER_WARN(...) Amethyst::Logging::GetServerLogger()->warn(__VA_ARGS__)
#define SERVER_ERROR(...) Amethyst::Logging::GetServerLogger()->error(__VA_ARGS__)

#define CLIENT_TRACE(...) Amethyst::Logging::GetClientLogger()->trace(__VA_ARGS__)
#define CLIENT_INFO(...) Amethyst::Logging::GetClientLogger()->info(__VA_ARGS__)
#define CLIENT_WARN(...) Amethyst::Logging::GetClientLogger()->warn(__VA_ARGS__)
#define CLIENT_ERROR(...) Amethyst::Logging::GetClientLogger()->error(__VA_ARGS__)
