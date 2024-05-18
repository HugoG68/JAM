/*
** EPITECH PROJECT, 2024
** JAM
** File description:
** Obstacle
*/

#pragma once
#include "AEntity.hpp"
#include <random>

namespace Entity
{
    class Obstacle : public AEntity {
        public:
            Obstacle() : AEntity(start_pos(), 0.01) {};
            virtual ~Obstacle() = default;

            EntityType get_type() const override {
                return ObstacleType;
            }
        
        protected:
        private:
            std::tuple<double, double> start_pos() const {
                static std::random_device rd;
                static std::mt19937 gen(rd());
                static std::uniform_real_distribution<> dis(0.0, 1.0);
                
                double random_y = dis(gen);
                return std::make_tuple(1.0, random_y);
            }
};

} // namespace Entity

