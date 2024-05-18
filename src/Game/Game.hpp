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
#include "../Text/Text.hpp"
#include "../Factory/Factory.hpp"
#include "../DeadPage/DeadPage.hpp"
#include <vector>
#include <memory>
#include <algorithm>
#include <SFML/Audio.hpp>

class Game : public IDisplay, public IFeature, public Object, public Text {
    public:
        Game(int multiplier);
        ~Game();

        void run() override;
        void update() override;
        void handleInput() override;
        bool isClosed() override;

        void addScore(int value) override;
        int getScore() const override;
        void setClickValue(int value) override;
        int getClickValue() const override;
        int getMultiplier() const { return _multiplier;}

        void displayObstacle(std::tuple<double, double> pos, Entity::EntityType type);
        void updateObstacles();
        sf::RenderWindow _window;
        int _score;
        int _clickValue;
        Player p;
        Object _background;
        Object _background2;
        Object _background3;
        int _multiplier;
        Text _scoretxt;
        sf::Clock deathClock;
        bool _close;
        bool deathClockStarted;

    protected:
        
        std::vector<std::unique_ptr<Entity::IEntity>> _obstacles;
        sf::Clock _obstacleSpawnClock;
        sf::Clock _fuelSpawnClock;
        sf::SoundBuffer _soundBuffer;
        sf::Sound _sound;
        sf::Clock _scoreClock;
    private:
        sf::Texture obstacleTexture;
        sf::Texture fuelTexture;
        sf::Clock _animationClock;
        int _currentFrame = 0;
        float _frameDuration = 0.1f;
        int _numFrames = 7;
        Entity::Player p_math = Entity::Player();
};
