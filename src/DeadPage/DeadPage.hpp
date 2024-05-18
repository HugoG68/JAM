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
#include <vector>
#include <memory>
#include <algorithm>
#include <SFML/Audio.hpp>

class Dead : public IDisplay, public Object, public Text {
    public:
        Dead(Text score);
        ~Dead();

        void run() override;
        void update() override;
        void handleInput() override;
        bool isClosed() override;
    protected:
        sf::RenderWindow _window;
        Text _score;
        bool _close;
    private:
};
