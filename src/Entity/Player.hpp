
#pragma once
#include "AEntity.hpp"

namespace Entity
{
class Player : public AEntity
{
public:
    EntityType get_type() const {
        return PlayerType;
    };
    Player(): AEntity({0.0, 0.0}, 0.001) {};
    ~Player() = default;
};


} // namespace Entity