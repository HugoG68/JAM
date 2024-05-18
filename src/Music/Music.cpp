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
        _music.setVolume(1000);
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