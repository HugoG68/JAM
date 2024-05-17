
#pragma once
#include "AEntity.hpp"

namespace Entity
{
class Player : public AEntity
{
public:
    EntityType get_type() const override {
        return PlayerType;
    };
    std::tuple<double, double> start_pos() const override {
        return std::tuple<double, double>({0.0, 0.0});
    };
    double speed() const override {
        return 0.001;
    };
    Player() {};
    ~Player() = default;
};


} // namespace Entity