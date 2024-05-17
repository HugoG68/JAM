/*
** EPITECH PROJECT, 2024
** B-PDG-300-MLH-3-1-PDGRUSH3-philippe.mahapatra
** File description:
** Main JAM
*/

#include <iostream>
#include "Game/Game.hpp"

int main(int ac, char **av)
{    
    if (ac == 1) {
        Game game;
        game.run();
        return 0;
    }    
    return 0;
}