#include "Amethyst/Logging.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>

using namespace Amethyst;

std::shared_ptr<spdlog::logger> Logging::sEngineLogger;
std::shared_ptr<spdlog::logger> Logging::sApplicationLogger;

void Logging::Init() {
    spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
    sEngineLogger = spdlog::stdout_color_mt("Server");
    sApplicationLogger = spdlog::stdout_color_mt("Client");
    sEngineLogger->set_level(spdlog::level::trace);
    sApplicationLogger->set_level(spdlog::level::trace);
}
