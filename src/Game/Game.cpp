/*
** EPITECH PROJECT, 2024
** Jam
** File description:
** Game
*/

#include "Game.hpp"

Factory factory;

Game::Game(int multiplier) : _window(sf::VideoMode(1920, 1080), "Olympic Jet"), _score(0),
    _clickValue(1),
    p("assets/man_sans_flamme.png"),
    _background("assets/Background_1.png", 0, 0, 1.0, 1.0),
    _background2("assets/Background_2.png", 1920, 0, 1.0, 1.0),
    _background3("assets/Background_3.png", 3840, 0, 1.0, 1.0),
    _multiplier(multiplier),
    _scoretxt(".", "assets/Fonts/Power Punchy.otf", sf::Color::Black, 50, 20, sf::Vector2f(0.25, 0.25)),
    _close(true),
    deathClockStarted(false),
    _win(0),
    _backscore("assets/avion.png", -20, -90, 0.3, 0.3)
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

    _fuelBarBackground.setSize(sf::Vector2f(20, 200));
    _fuelBarBackground.setFillColor(sf::Color::Black);
    _fuelBarBackground.setPosition(50, 90);

    _fuelBar.setSize(sf::Vector2f(20, 200));
    _fuelBar.setFillColor(sf::Color::Yellow);
    _fuelBar.setPosition(50, 90);
}

Game::~Game()
{
    _close = true;
    _window.close();
}

void Game::run()
{
    while (_window.isOpen())
    {
        sf::Vector2f backgroundPosition = _background.getPosition();
        sf::Vector2f backgroundPosition2 = _background2.getPosition();
        sf::Vector2f backgroundPosition3 = _background3.getPosition();  
        if (p.is_alive()) {
            backgroundPosition.x -= 1.0f;
            backgroundPosition2.x -= 1.0f;
            backgroundPosition3.x -= 1.0f;
        }
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

        int cutHeight = 400;
        obstacle.setTextureRect(sf::IntRect(
            _currentFrame * frameWidth,
            cutHeight,
            frameWidth,
            frameHeight - 2 * cutHeight
        ));
    }
    obstacle.setPosition(std::get<0>(pos), std::get<1>(pos));
    _window.draw(obstacle);
}

void Game::updateObstacles()
{
    p.set_size(std::make_tuple(static_cast<double>(p.frameWidth), static_cast<double>(p.frameHeight)));

    _obstacles.erase(
        std::remove_if(_obstacles.begin(), _obstacles.end(), [this](const std::unique_ptr<Entity::IEntity>& obstacle) {
            for (int i = 0; i < getMultiplier(); i++)
                obstacle->go_left();
            return std::get<0>(obstacle->get_pos()) <= -100.01;
        }),
        _obstacles.end()
    );

    for (auto it = _obstacles.begin(); it != _obstacles.end(); ) {
        auto &obstacle = *it;
        std::tuple<double, double> size;
        displayObstacle(obstacle->get_pos(), obstacle->get_type());

        if (obstacle->get_type() == Entity::EntityType::ObstacleType) {
            sf::Vector2u textureSize = obstacleTexture.getSize();
            size = std::make_tuple(static_cast<double>(textureSize.x) * 0.1, static_cast<double>(textureSize.y) * 0.1);
        } else if (obstacle->get_type() == Entity::EntityType::FuelType) {
            sf::Vector2u textureSize = fuelTexture.getSize();
            size = std::make_tuple(static_cast<double>(textureSize.x) / _numFrames, static_cast<double>(textureSize.y));
        }
        obstacle->set_size(size);

        if (p.hits(obstacle)) {
            if (obstacle->get_type() == Entity::EntityType::FuelType) {
                it = _obstacles.erase(it);
                continue;
            }
        }
        ++it;
    }

    if (_obstacleSpawnClock.getElapsedTime().asSeconds() > 1) {
        _obstacleSpawnClock.restart();
        _obstacles.push_back(factory.create(Entity::EntityType::ObstacleType));
    }

    if (_fuelSpawnClock.getElapsedTime().asSeconds() > 2) {
        _fuelSpawnClock.restart();
        _obstacles.push_back(factory.create(Entity::EntityType::FuelType));
    }

    if (!p.is_alive())
    {
        p.setTexture("assets/dead.png");
        p.setScale(1.2, 1.2);
        _window.display();
        if (!deathClockStarted) {
            deathClock.restart();
            deathClockStarted = true;
        }
        if (deathClock.getElapsedTime().asSeconds() >= 4) {
            _sound.stop();
            _close = false;
            _window.close();
            Dead dead(_scoretxt);
            dead.run();
        }
    }
    if (_score > 250) {
        _sound.stop();
        Win _win(_scoretxt);
        _window.close();
        _win.run();
    }
}

void Game::update()
{
    _window.clear();
    _background.drawBackground(_window);
    _background2.drawBackground(_window);
    _background3.drawBackground(_window);
    _backscore.drawBackground(_window);
    p.draw(_window);
    p.update(0.025);

    if (_scoreClock.getElapsedTime().asSeconds() >= 0.3f) {
        addScore(1);
        _scoreClock.restart();
    }

    _scoretxt.setContent("Score: " + std::to_string(getScore()));
    _scoretxt.draw(_window);
    updateObstacles();

    float fuelLevel = static_cast<float>(p.get_fuel());
    _fuelBar.setSize(sf::Vector2f(20, 200 * fuelLevel));
    _fuelBar.setPosition(50, 90 + (200 - _fuelBar.getSize().y));

    _window.draw(_fuelBarBackground);
    _window.draw(_fuelBar);

    _window.display();
}

void Game::handleInput()
{
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window.close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && p.is_alive()) {
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

bool Game::isClosed()
{
    return _close;
}
