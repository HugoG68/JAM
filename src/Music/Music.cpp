/*
** EPITECH PROJECT, 2024
** JAM
** File description:
** Music
*/

#include "Music.hpp"

Music::Music() : _isMute(false)
{

}

Music::Music(const std::string music) : _isMute(false)
{
    if (_music.openFromFile(music)) {
        _music.play();
        _music.setLoop(true);
        _music.setVolume(100);
    }
}

Music::~Music()
{
    _music.stop();
}

void Music::pause() {
    if (_music.getStatus() == sf::Music::Playing) {
        _music.pause();
        _isMute = true;
    }
}

void Music::resume() {
    if (_isMute) {
        _music.play();
        _isMute = false;
    }
}

void Music::stop() {
    _music.stop();
}

void Music::setVolume(float volume) {
    if (volume < 0.0f) {
        volume = 0.0f;
    } else if (volume > 100.0f)
        volume = 100.0f;
    _music.setVolume(volume);
}

float Music::getVolume() {
    return _music.getVolume();
}