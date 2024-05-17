/*
** EPITECH PROJECT, 2024
** JAM
** File description:
** IFactory
*/

#ifndef IFACTORY_HPP_
    #define IFACTORY_HPP_

    #include "../Entity/IEntity.hpp"
class IFactory {
    public:
        virtual ~IFactory() = default;
        virtual IEntity *create() = 0;

    protected:
    private:
};

#endif /* !IFACTORY_HPP_ */
