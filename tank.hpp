#ifndef TANK_HPP
#define TANK_HPP

#define SHOT_COOLDOWN_DEFAULT_VALUE 10

#include "bullet.hpp"

class Tank : public MovingObject
{
private:
	int showCooldown;
public:
};

#endif