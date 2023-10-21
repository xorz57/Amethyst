#pragma once

#include "PCH.hpp"

namespace Amethyst {
    class Layer {
    public:
        explicit Layer(std::string name);
        virtual ~Layer() = default;
        virtual void OnAttach() = 0;
        virtual void OnDetach() = 0;
        virtual void OnFixedUpdate(double dt) = 0;
        virtual void OnUpdate(double dt) = 0;
        virtual void OnLateUpdate(double dt) = 0;
        [[nodiscard]] std::string GetName() const;

    private:
        std::string mName;
    };
}// namespace Amethyst
