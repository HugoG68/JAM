/*** EPITECH PROJECT, 2024
** JAM
** File description:
** Game
*/

#pragma once

#include "../IDisplay/IDisplay.hpp"
#include "../IFeature/IFeature.hpp"
#include "../Player/Player.hpp"
#include "../Menu/Menu.hpp"
#include "../Menu/Button.hpp"
#include "../Object/Object.hpp"
#include "../Text/Text.hpp"
#include "../Game/Game.hpp"
#include "../Factory/Factory.hpp"
#include <vector>
#include <memory>
#include <algorithm>
#include <SFML/Audio.hpp>

class Win : public IDisplay, public Object, public Text, public Button {
    public:
        Win(Text score);
        ~Win();

        void run() override;
        void update() override;
        void handleInput() override;
        bool isClosed() override;
    protected:
        sf::RenderWindow _window;
        Text _score;
        bool _close;
        Object _background;
        Text _tittle;
        Button _home;
        Button _restart;
        Object _flamme;
    private:
};
