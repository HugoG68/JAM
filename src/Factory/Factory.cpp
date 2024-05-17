/*
** EPITECH PROJECT, 2024
** JAM
** File description:
** Factory
*/

#include "Factory.hpp"

Factory::Factory()
{
    _map[Entity::EntityType::Player] = []() {return std::make_unique<Entity::IEntity>();};
}

std::unique_ptr<Entity::IEntity> Factory::create(Entity::EntityType Type)
{
    return std::make_unique<Entity::IEntity>();
}
