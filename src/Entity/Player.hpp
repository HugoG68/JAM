
#pragma once
#include "AEntity.hpp"

namespace Entity
{
class Player : public AEntity
{
private:
    double _fuel;
    void increase_fuel(double added) {
        _fuel += added;
        if (_fuel > 1.0)
            _fuel = 1.0;
    }

    const double FUEL_GAIN = 0.01;
    const double FUEL_LOSS = 0.01;

public:
    EntityType get_type() const {
        return PlayerType;
    };
    Player(): AEntity({0.0, 0.0}, 0.01) {};
    ~Player() = default;
    void go_up(void) override {
        if (_fuel > FUEL_LOSS) {
            _fuel -= FUEL_LOSS;
            AEntity::go_up();
        }
    }
};


} // namespace Entity
