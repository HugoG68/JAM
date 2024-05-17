/*
** EPITECH PROJECT, 2024
** JAM
** File description:
** Factory
*/

#include "Factory.hpp"

Factory::Factory()
{
    _map[Entity::EntityType::PlayerType] = []() {return std::make_unique<Entity::Player>(); };
    _map[Entity::EntityType::ObstacleType] = []() {return std::make_unique<Entity::Obstacle>(); };
}

std::unique_ptr<Entity::IEntity> Factory::create(Entity::EntityType Type)
{
    auto it = _map.find(Type);
    if (it != _map.end()) {
        return it->second();
    }
    return nullptr;
}
