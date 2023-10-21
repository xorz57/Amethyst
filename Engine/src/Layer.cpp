#include "Amethyst/Layer.hpp"

using namespace Amethyst;

Layer::Layer(std::string name) : mName(std::move(name)) {}

std::string Layer::GetName() const {
    return mName;
}
