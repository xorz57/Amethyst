#pragma once

#include "PCH.hpp"

namespace Amethyst {
    class Shader {
    public:
        Shader(const char *vShaderPath, const char *fShaderPath);

        void Use() const;
        void SetBool(const std::string &name, bool value) const;
        void SetInt(const std::string &name, int value) const;
        void SetFloat(const std::string &name, float value) const;
        [[nodiscard]] unsigned int GetID() const;

    private:
        unsigned int mID;
    };
}// namespace Amethyst
