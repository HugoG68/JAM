/*
** EPITECH PROJECT, 2024
** JAM
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
    #define FACTORY_HPP_

    #include <map>
    #include <memory>
    #include <functional>
    #include "Entity/IEntity.hh"
    #include "Entity/Player.hpp"
    #include "Entity/Obstacle.hpp"

    class Factory {
        private:
            std::map<Entity::EntityType, std::function<std::unique_ptr<Entity::IEntity>()>> _map;
        public:
            Factory();
            ~Factory() = default;
            std::unique_ptr<Entity::IEntity> create(Entity::EntityType Type);
    };

#endif /* !FACTORY_HPP_ */
