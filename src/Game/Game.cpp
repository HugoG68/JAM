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
    _background("assets/Background_1.png", 0, 0, 1.0, 1.0),
    _background2("assets/Background_2.png", 1920, 0, 1.0, 1.0),
    _background3("assets/Background_3.png", 3840, 0, 1.0, 1.0),
    _multiplier(multiplier),
    _scoretxt(".", "assets/Fonts/Power Punchy.otf", sf::Color::Black, 50, 10, sf::Vector2f(0.35, 0.35))
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
    if (!fuelTexture.loadFromFile("spritesheets/flamme.png")) {
        std::cerr << "Failed to load fuel texture from file 'spritesheets/flamme.png'" << std::endl;
        exit(EXIT_FAILURE);
    }
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
        sf::Vector2f backgroundPosition2 = _background2.getPosition();
        sf::Vector2f backgroundPosition3 = _background3.getPosition();  
        backgroundPosition.x -= 1.0f;
        backgroundPosition2.x -= 1.0f;
        backgroundPosition3.x -= 1.0f;
        if (backgroundPosition.x <= -1920)
            backgroundPosition.x = backgroundPosition3.x + 1920;
        if (backgroundPosition2.x <= -1920)
            backgroundPosition2.x = backgroundPosition.x + 1920;
        if (backgroundPosition3.x <= -1920)
            backgroundPosition3.x = backgroundPosition2.x + 1920;
        _background.setPosition(backgroundPosition);
        _background2.setPosition(backgroundPosition2);
        _background3.setPosition(backgroundPosition3);
        handleInput();
        update();
    }
}

void Game::displayObstacle(std::tuple<double, double> pos, Entity::EntityType type)
{
    sf::Sprite obstacle;

    if (type == Entity::EntityType::ObstacleType) {
        obstacle.setTexture(obstacleTexture);
        obstacle.setScale(0.1f, 0.1f);
    } else if (type == Entity::EntityType::FuelType) {
        obstacle.setTexture(fuelTexture);

        if (_animationClock.getElapsedTime().asSeconds() >= _frameDuration)
        {
            _currentFrame = (_currentFrame + 1) % _numFrames;
            _animationClock.restart();
        }

        int frameWidth = fuelTexture.getSize().x / _numFrames;
        int frameHeight = fuelTexture.getSize().y;
        obstacle.setTextureRect(sf::IntRect(_currentFrame * frameWidth, 0, frameWidth, frameHeight));
    }
    obstacle.setPosition(std::get<0>(pos) * 1920, std::get<1>(pos) * 1080);
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
        displayObstacle(obstacle->get_pos(), obstacle->get_type());
    }

    if (_obstacleSpawnClock.getElapsedTime().asSeconds() > 1)
    {
        _obstacleSpawnClock.restart();
        _obstacles.push_back(factory.create(Entity::EntityType::ObstacleType));
    }

    if (_fuelSpawnClock.getElapsedTime().asSeconds() > 2)
    {
        _fuelSpawnClock.restart();
        _obstacles.push_back(factory.create(Entity::EntityType::FuelType));
    }
}

void Game::update()
{
    _window.clear();
    _background.drawBackground(_window);
    _background2.drawBackground(_window);
    _background3.drawBackground(_window);
    p.draw(_window);
    p.update(0.025);

    if (_scoreClock.getElapsedTime().asSeconds() >= 0.5f) {
        addScore(1);
        _scoreClock.restart();
    }

    _scoretxt.setContent("Score: " + std::to_string(getScore()));
    _scoretxt.draw(_window);
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
