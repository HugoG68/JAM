#pragma once
#include "Obstacle.hpp"

namespace Entity
{
    class Fuel: public Obstacle
    {
    public:
        ~Fuel() = default;
        EntityType get_type() const override {
            return FuelType;
        }
    };
    
} // namespace Entity
