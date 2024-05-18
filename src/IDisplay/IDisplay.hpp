/*
** EPITECH PROJECT, 2024
** JAM
** File description:
** IDisplay
*/

#pragma once

class IDisplay {
    public:
        virtual void run() = 0;
        virtual void update() = 0;
        virtual void handleInput() = 0;
        virtual bool isClosed() = 0;

    protected:
    private:
};
