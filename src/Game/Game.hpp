/*** EPITECH PROJECT, 2024
** CrimsonClicker
** File description:
** Game
*/

#pragma once

#include "../IDisplay/IDisplay.hpp"
#include "../IFeature/IFeature.hpp"
#include "../Player/Player.hpp"
#include "../Object/Object.hpp"
#include "../Factory/Factory.hpp"
#include <vector>
#include <memory>
#include <algorithm>
#include <SFML/Audio.hpp>

class Game : public IDisplay, public IFeature, public Object {
    public:
        Game(int multiplier);
        ~Game();

        void run() override;
        void update() override;
        void handleInput() override;

        void addScore(int value) override;
        int getScore() const override;
        void setClickValue(int value) override;
        int getClickValue() const override;
        int getMultiplier() const { return _multiplier;}

        void displayObstacle(std::tuple<double, double> pos);
        void updateObstacles();

    protected:
        sf::RenderWindow _window;
        int _score;
        int _clickValue;
        int _multiplier;
        Player p;
        Object _background;
        std::vector<std::unique_ptr<Entity::IEntity>> _obstacles;
        sf::Clock _obstacleSpawnClock;
        sf::SoundBuffer _soundBuffer;
        sf::Sound _sound;
    private:
};
