#pragma once

#include "Engine/Layer.hpp"

namespace Amethyst::Editor {
    class Layer : public Amethyst::Engine::Layer {
    public:
        explicit Layer(std::string name);
        void OnAttach() override;
        void OnDetach() override;
        void OnFixedUpdate(double dt) override;
        void OnUpdate(double dt) override;
    };
}// namespace Editor
