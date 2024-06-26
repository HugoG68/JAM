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
#include "../Menu/Menu.hpp"
#include "../Factory/Factory.hpp"
#include "../Menu/Button.hpp"
#include "../Flame/Flame.hpp"
#include <vector>
#include <memory>
#include <algorithm>
#include <SFML/Audio.hpp>

enum class GameState {
    Playing,
    Win,
    Loose
};

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
        int getMultiplier() const { return _multiplier; }

        void displayObstacle(std::tuple<double, double> pos, Entity::EntityType type, int textureIndex);
        void updateObstacles();
        void displayWinPage();
        void drawBackground();
        void displayLoosePage();

    private:
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
        int _win;
        Object _backscore;
        std::vector<std::unique_ptr<Entity::IEntity>> _obstacles;
        sf::Clock _obstacleSpawnClock;
        sf::Clock _fuelSpawnClock;
        sf::SoundBuffer _soundBuffer;
        sf::Sound _sound;
        sf::Clock _scoreClock;
        sf::Texture obstacleTexture;
        sf::Texture obstacleTexture2;
        sf::Texture obstacleTexture3;
        sf::Texture obstacleTexture4;
        sf::Texture obstacleTexture5;
        sf::Texture fuelTexture;
        sf::Clock _animationClock;
        int _currentFrame = 0;
        float _frameDuration = 0.1f;
        int _numFrames = 7;
        sf::RectangleShape _fuelBarBackground;
        sf::RectangleShape _fuelBar;

        GameState _gameState;

        Object _winBackground;
        Text _winTittle;
        Button _homeButton;
        Button _restartButton;
        Object _winFlamme;
        Object _looseBackground;
        Text _looseTittle;
        Button _looseHomeButton;
        Button _looseRestartButton;
        Flame _flame;
        sf::Clock _flameClock;
};
