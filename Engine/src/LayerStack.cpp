#include "Amethyst/LayerStack.hpp"

using namespace Amethyst;

void LayerStack::Push(std::unique_ptr<Layer> layer) {
    mLayers.push_back(std::move(layer));
    mLayers.back()->OnAttach();
}

void LayerStack::Pop() {
    if (!mLayers.empty()) {
        mLayers.back()->OnDetach();
        mLayers.pop_back();
    }
}

void LayerStack::Clear() {
    for (const std::unique_ptr<Layer> &layer: mLayers) {
        layer->OnDetach();
    }
    mLayers.clear();
}

void LayerStack::FixedUpdate(double dt) const {
    for (const std::unique_ptr<Layer> &layer: mLayers) {
        layer->OnFixedUpdate(dt);
    }
}

void LayerStack::Update(double dt) const {
    for (const std::unique_ptr<Layer> &layer: mLayers) {
        layer->OnUpdate(dt);
    }
}

std::size_t LayerStack::Size() const {
    return mLayers.size();
}
