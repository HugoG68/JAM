/*
** EPITECH PROJECT, 2024
** JAM
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
    #define FACTORY_HPP_

    #include "IFactory.hpp"
    #include <memory>

class AFactory : public IFactory {
    public:
        IEntity *create() override;

    protected:
    private:
};

#endif /* !FACTORY_HPP_ */
