
#pragma once
#include "AEntity.hpp"
#include <iostream>
#include <memory>

namespace Entity
{
class Player : public AEntity
{
private:
    double _fuel;

    const double FUEL_GAIN = 0.075;
    const double FUEL_LOSS = 0.003;

public:
    bool _is_alive;
    EntityType get_type() const {
        return PlayerType;
    };
    Player(): AEntity({100.0, 300.0}, 0.01), _fuel(1.0), _is_alive(true) {};
    ~Player() = default;
    void go_up(void) override {
        if (_fuel > FUEL_LOSS) {
            _fuel -= FUEL_LOSS;
            AEntity::go_up();
        }
    }
    bool hits(const std::unique_ptr<Entity::IEntity> &obstacle) {
        std::tuple<double, double> player_pos = get_pos();
        std::tuple<double, double> obstacle_pos = obstacle->get_pos();
        std::tuple<double, double> player_size = get_size();
        std::tuple<double, double> obstacle_size = obstacle->get_size();
        EntityType obstacle_type = obstacle->get_type();

        const double playerScaleFactor = 0.8;
        const double obstacleScaleFactor = 0.5;

        double playerHitboxWidth = std::get<0>(player_size) * playerScaleFactor;
        double playerHitboxHeight = std::get<1>(player_size) * playerScaleFactor;
        double playerHitboxX = std::get<0>(player_pos) + (std::get<0>(player_size) - playerHitboxWidth) / 2;
        double playerHitboxY = std::get<1>(player_pos) + (std::get<1>(player_size) - playerHitboxHeight) / 2;

        double obstacleHitboxWidth = std::get<0>(obstacle_size) * obstacleScaleFactor;
        double obstacleHitboxHeight = std::get<1>(obstacle_size) * obstacleScaleFactor;
        double obstacleHitboxX = std::get<0>(obstacle_pos) + (std::get<0>(obstacle_size) - obstacleHitboxWidth) / 2;
        double obstacleHitboxY = std::get<1>(obstacle_pos) + (std::get<1>(obstacle_size) - obstacleHitboxHeight) / 2;

        if (!(playerHitboxX < obstacleHitboxX + obstacleHitboxWidth &&
            playerHitboxX + playerHitboxWidth > obstacleHitboxX &&
            playerHitboxY < obstacleHitboxY + obstacleHitboxHeight &&
            playerHitboxY + playerHitboxHeight > obstacleHitboxY)) {
            return false;
        }
        if (obstacle_type == ObstacleType) {
            _is_alive = false;
            return false;
        }
        if (obstacle_type == FuelType) {
            _fuel += FUEL_GAIN;
            if (_fuel > 1.0)
                _fuel = 1.0;
            return true;
        }
        return false;
    }

    bool is_alive() const {
        return _is_alive;
    }
    bool have_fuel() const {
        return _fuel > 0.0;
    }
    double get_fuel() const {
        return _fuel;
    }

    void burn_fuel() {
        _fuel -= FUEL_LOSS;
    }
}; 


} // namespace Entity
