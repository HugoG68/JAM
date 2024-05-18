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

class Game : public IDisplay, public IFeature, public Object {
    public:
        Game();
        ~Game();

        void run() override;
        void update() override;
        void handleInput() override;

        void addScore(int value) override;
        int getScore() const override;
        void setClickValue(int value) override;
        int getClickValue() const override;

    protected:
        sf::RenderWindow _window;
        int _score;
        int _clickValue;
        Player p;
        Object _background;
    private:
};
