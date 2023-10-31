#pragma once

#include "PCH.hpp"

#include "Engine/Layer.hpp"

namespace Amethyst::Engine {
    class LayerStack {
    public:
        LayerStack() = default;
        void Push(std::unique_ptr<Layer> layer);
        void Pop();
        void Clear();
        void FixedUpdate(double dt) const;
        void Update(double dt) const;
        [[nodiscard]] std::size_t Size() const;

    private:
        std::vector<std::unique_ptr<Layer>> mLayers;
    };
}// namespace Amethyst::Engine
