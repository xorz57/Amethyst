#pragma once

#include "PCH.hpp"

namespace Amethyst {
    class Shader {
    public:
        Shader() = default;
        ~Shader() = default;
        [[nodiscard]] std::uint32_t GetID() const;

    private:
        std::uint32_t mID;
    };
}// namespace Amethyst
