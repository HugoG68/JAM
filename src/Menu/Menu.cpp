/*
** EPITECH PROJECT, 2024
** JAM
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu() : _window(sf::VideoMode(1920, 1080), "JetPack Menu", sf::Style::Default),
    _close(true),
    _start("assets/Button/Start Button.png", 950, 500, 1.0, 1.0),
    _quit("assets/Button/Quit Button.png", 950, 800, 1.0, 1.0),
    _settings("assets/Button/Settings Button.png", 950, 650, 1.0, 1.0),
    _background("assets/Olympic_Jet.png", 0, 0, 1.0, 1.0),
    _jetback("assets/solo_man_jetpack.png", 350, 200, 0.6, 0.6, 30),
    _music("assets/sous_le_ciel_de_paris.ogg"),
    _settingsdraw(false),
    _backsettings("assets/backsettings.png", 370, 120, 1.0, 1.0),
    _closeSettings("assets/Button/X Square Button.png", 1220, 430, 0.3, 0.3),
    _soundBtn("assets/Button/Pause Square Button.png", 1100, 500, 0.3, 0.3),
    _isMusicPlaying(true),
    _soundBtnMute("assets/Button/Play Square Button.png", 1100, 500, 0.3, 0.3),
    _musicSettings("Music", "assets/Fonts/Power Punchy.otf", sf::Color::Black, 650, 470, sf::Vector2f(0.35, 0.35)),
    _levelSettings("Difficulty", "assets/Fonts/Power Punchy.otf", sf::Color::Black, 650, 670, sf::Vector2f(0.35, 0.35)),
    _level("assets/easy.png", 1100, 690, 0.3, 0.3),
    _currentLevelIndex(0),
    _currentDifficulty(Easy),
    _soundtxt(".", "assets/Fonts/Power Punchy.otf", sf::Color::Black, 650, 570, sf::Vector2f(0.35, 0.35)),
    _plus("assets/Button/Up Square Button.png", 1200, 600, 0.2, 0.2),
    _moins("assets/Button/Down Square Button.png", 980, 600, 0.2, 0.2)
{
    _levelTextures[0].loadFromFile("assets/easy.png");
    _levelTextures[1].loadFromFile("assets/normal.png");
    _levelTextures[2].loadFromFile("assets/hard.png");
    _level._sprite.setTexture(_levelTextures[_currentLevelIndex]);

    sf::Image icon;
    if (!icon.loadFromFile("assets/logo.png")) {
        std::cerr << "Erreur de chargement de l'icône." << std::endl;
    } else {
        _window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    }
}

Menu::~Menu()
{
    _window.close();
}

void Menu::run()
{
    while (_window.isOpen())
    {
        handleInput();
        update();
    }
}

void Menu::update()
{
    _window.clear();
    _background.drawBackground(_window);
    _jetback.drawBackground(_window);
    _start.display(_window);
    _quit.display(_window);
    _settings.display(_window);
    _tittle.draw(_window);
    _tittle2.draw(_window);

    _soundtxt.setContent("Volume:              " + std::to_string(static_cast<int>(_music.getVolume())) + "%");

    if (_settingsdraw == true) {
        _backsettings.drawBackground(_window);
        _closeSettings.display(_window);
        _soundBtn.display(_window);
        _musicSettings.draw(_window);
        _levelSettings.draw(_window);
        _level.display(_window);
        _soundtxt.draw(_window);
        _plus.display(_window);
        _moins.display(_window);
        if (_isMusicPlaying) {
            _soundBtn.display(_window);
        } else {
            _soundBtnMute.display(_window);
        }
    }

    _window.display();

    if (_start.isClicked(_window)) {
        _start._sprite.setScale(0.55 , 0.55);
    } else
        _start._sprite.setScale(0.5 , 0.5);
    if (_quit.isClicked(_window)) {
        _quit._sprite.setScale(0.55 , 0.55);
    } else
        _quit._sprite.setScale(0.5 , 0.5);
    if (_settings.isClicked(_window)) {
        _settings._sprite.setScale(0.55 , 0.55);
    } else
        _settings._sprite.setScale(0.5 , 0.5);
    if (_closeSettings.isClicked(_window)) {
        _closeSettings._sprite.setScale(0.33 , 0.33);
    } else
        _closeSettings._sprite.setScale(0.3 , 0.3);
    if (_soundBtn.isClicked(_window)) {
        _soundBtn._sprite.setScale(0.33 , 0.33);
    } else
        _soundBtn._sprite.setScale(0.3 , 0.3);
    if (_level.isClicked(_window)) {
        _level._sprite.setScale(0.33 , 0.33);
    } else
        _level._sprite.setScale(0.3 , 0.3);
}

void Menu::handleInput()
{
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window.close();
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _start.isClicked(_window) && _settingsdraw == false) {
            _close = false;
            _window.close();
            if (_win == 1) {
                _music.stop();
                Game game(getCurrentDifficulty());
                game.run();
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _quit.isClicked(_window) && _settingsdraw == false) {
            _window.close();
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _settings.isClicked(_window) && _settingsdraw == false) {
            _settingsdraw = !_settingsdraw;
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _closeSettings.isClicked(_window) && _settingsdraw == true) {
            _settingsdraw = !_settingsdraw;
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _soundBtn.isClicked(_window) && _settingsdraw == true) {
            _isMusicPlaying = !_isMusicPlaying;
            if (_isMusicPlaying) {
                _music.resume();
            } else {
                _music.pause();
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _level.isClicked(_window) && _settingsdraw) {
            cycleLevelTexture();
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _plus.isClicked(_window) && _settingsdraw)
            _music.setVolume(_music.getVolume() + 10);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _moins.isClicked(_window) && _settingsdraw)
            _music.setVolume(_music.getVolume() - 10);
    }
}

void Menu::cycleLevelTexture()
{
    _currentLevelIndex = (_currentLevelIndex + 1) % 3;
    _level._sprite.setTexture(_levelTextures[_currentLevelIndex]);

    switch (_currentLevelIndex) {
        case 0:
            _currentDifficulty = Easy;
            break;
        case 1:
            _currentDifficulty = Medium;
            break;
        case 2:
            _currentDifficulty = Hard;
            break;
    }
}

bool Menu::isClosed()
{
    _music.stop();
    return _close;
}

