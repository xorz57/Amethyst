#pragma once

#include "Amethyst/Layer.hpp"

class SandboxLayer : public Amethyst::Layer {
public:
    explicit SandboxLayer(std::string name);
    void OnAttach() override;
    void OnDetach() override;
    void OnFixedUpdate(double dt) override;
    void OnUpdate(double dt) override;
    void OnLateUpdate(double dt) override;
};
