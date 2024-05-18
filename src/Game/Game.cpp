/*
** EPITECH PROJECT, 2024
** Jam
** File description:
** Game
*/

#include "Game.hpp"

Factory factory;

Game::Game(int multiplier) : _window(sf::VideoMode(1920, 1080), "Crimson Clicker"), _score(0),
    _clickValue(1),
    p("assets/man_sans_flamme.png"),
    _background("assets/Background.png", 0, 0, 1.2, 1.0)
{
    if (!_soundBuffer.loadFromFile("assets/jetpack.ogg")) {
        std::cerr << "Critical Error: Failed to load sound file 'assets/sound.ogg'. Exiting." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    _sound.setBuffer(_soundBuffer);
    _sound.setLoop(true);
    _window.setFramerateLimit(60);
    _multiplier = multiplier;
    if (!obstacleTexture.loadFromFile("assets/balle_basket.png")) {
        std::cerr << "Failed to load obstacle texture from file 'assets/balle_basket.png'" << std::endl;
        exit(EXIT_FAILURE);
    }
    _sound.setBuffer(_soundBuffer);
    _sound.setLoop(true);
    _window.setFramerateLimit(60);
    _multiplier = multiplier;
}

Game::~Game()
{
    _window.close();
}

void Game::run()
{
    while (_window.isOpen())
    {
        sf::Vector2f backgroundPosition = _background.getPosition();
         backgroundPosition.x -= 1.0f;
         _background.setPosition(backgroundPosition);
        handleInput();
        update();
    }
}

void Game::displayObstacle(std::tuple<double, double> pos)
{
    sf::Sprite obstacle(obstacleTexture);
    obstacle.setPosition(std::get<0>(pos) * 1920, std::get<1>(pos) * 1080);

    float scaleFactorX = 0.1f;
    float scaleFactorY = 0.1f;
    obstacle.setScale(scaleFactorX, scaleFactorY);
    _window.draw(obstacle);
}

void Game::updateObstacles()
{
    _obstacles.erase(
        std::remove_if(_obstacles.begin(), _obstacles.end(), [this](const std::unique_ptr<Entity::IEntity>& obstacle) {
            for (int i = 0; i < (getMultiplier()); i++)
                obstacle->go_left();
            if (std::get<0>(obstacle->get_pos()) <= 0.01) {
                return true;
            }
            return false;
        }),
        _obstacles.end()
    );

    for (auto &obstacle : _obstacles)
    {
        displayObstacle(obstacle->get_pos());
    }

    if (_obstacleSpawnClock.getElapsedTime().asSeconds() > 1)
    {
        _obstacleSpawnClock.restart();
        _obstacles.push_back(factory.create(Entity::EntityType::ObstacleType));
    }
}

void Game::update()
{
    _window.clear();
    _background.drawBackground(_window);
    p.draw(_window);
    p.update(0.025);

    updateObstacles();

    _window.display();
}

void Game::handleInput()
{
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window.close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        if (_sound.getStatus() != sf::Sound::Playing) {
            _sound.play();
        }
    } else {
        if (_sound.getStatus() == sf::Sound::Playing) {
            _sound.stop();
        }
    }
}

void Game::addScore(int value)
{
    _score += value;
}

int Game::getScore() const
{
    return _score;
}

void Game::setClickValue(int value)
{
    _clickValue = value;
}

int Game::getClickValue() const
{
    return _clickValue;
}
