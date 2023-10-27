#pragma once

#include "Amethyst/Layer.hpp"

class EditorLayer : public Amethyst::Layer {
public:
    explicit EditorLayer(std::string name);
    void OnAttach() override;
    void OnDetach() override;
    void OnFixedUpdate(double dt) override;
    void OnUpdate(double dt) override;
};
