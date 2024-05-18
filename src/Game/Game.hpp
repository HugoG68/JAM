/*** EPITECH PROJECT, 2024
** CrimsonClicker
** File description:
** Game
*/

#pragma once

#include "../IDisplay/IDisplay.hpp"
#include "../IFeature/IFeature.hpp"
#include "../Player/Player.hpp"
#include "../Factory/Factory.hpp"
#include <vector>
#include <memory>
#include <algorithm>

class Game : public IDisplay, public IFeature {
    public:
        Game();
        ~Game();

        void run() override;
        void update() override;
        void handleInput() override;

        void addScore(int value) override;
        int getScore() const override;
        void setClickValue(int value) override;
        int getClickValue() const override;

        void displayObstacle(std::tuple<double, double> pos);
        void updateObstacles();

    protected:
        sf::RenderWindow _window;
        int _score;
        int _clickValue;
        Player p;
        std::vector<std::unique_ptr<Entity::IEntity>> _obstacles;
        sf::Clock _obstacleSpawnClock;
    private:
};
