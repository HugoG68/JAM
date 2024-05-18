/*
** EPITECH PROJECT, 2024
** JAM
** File description:
** AEntity
*/

#pragma once
#include "IEntity.hh"

namespace Entity
{

class AEntity : public IEntity
{
private:
    std::tuple<double, double> _pos;
    std::tuple<double, double> _size;
    double _speed;

public:
    const double MAX_HEIGHT = 1080.0;
    const double MAX_WIDTH = 1920.0;
    AEntity(std::tuple<double, double> pos, double speed) :_pos(pos), _speed(speed) {};
    ~AEntity() = default;
    virtual void go_up(void) {
        double pos_y = std::get<1>(_pos);
        double new_pos_y = pos_y - _speed; 
        if (new_pos_y >= 0.0)
            std::get<1>(_pos) = new_pos_y;
    }
    virtual void go_left(void){
        double pos_x = std::get<0>(_pos);
        double new_pos_x = pos_x - _speed; 
        std::get<0>(_pos) = new_pos_x;
    }
    virtual void go_right(void){
        double pos_x = std::get<0>(_pos);
        double new_pos_x = pos_x + _speed; 
        if (new_pos_x <= (MAX_WIDTH - std::get<0>(_size)))
            std::get<0>(_pos) = new_pos_x;
    }
    virtual void go_down(void){
        double pos_y = std::get<1>(_pos);
        double new_pos_y = pos_y + _speed; 
        if (new_pos_y <= (MAX_HEIGHT - std::get<1>(_size)))
            std::get<1>(_pos) = new_pos_y;
    }
    virtual std::tuple<double, double> get_pos() const {
        return _pos;
    };
    virtual EntityType get_type() const {
        return UnknowType;
    };

    std::tuple<double, double> get_size() const {
        return _size;
    };

   void set_pos(std::tuple<double, double> pos) {
        _pos = pos;
    };
    void set_size(std::tuple<double, double> size) {
        _size = size;
    };

};

} // namespace Entity