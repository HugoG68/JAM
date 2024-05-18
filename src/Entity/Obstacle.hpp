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
            Obstacle() : AEntity(start_pos(), 10.0) {
                set_size(std::make_tuple(0.1, 0.1));
            };
            virtual ~Obstacle() = default;

            virtual EntityType get_type() const override {
                return ObstacleType;
            }
        
        protected:
        private:

            std::tuple<double, double> start_pos() const {
                static std::random_device rd;
                static std::mt19937 gen(rd());
                static std::uniform_real_distribution<> dis(0.2, MAX_HEIGHT);
                
                double random_y = dis(gen);
                return std::make_tuple(MAX_WIDTH, random_y);
            }
};

} // namespace Entity

