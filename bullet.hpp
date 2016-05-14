#ifndef BULLET_HPP
#define BULLET_HPP

#include "movingobject.hpp"
#include "velocity.hpp"

#include <iostream>
using std::cout;

#define DEFAULT_DX 0
#define DEFAULT_DY 8

class Bullet : public MovingObject
{
private:
	Velocity v;
public:
	Bullet(SDL_Renderer* r, const Point& p);

	virtual void draw();
	virtual void update();

	bool outOfBounds(const Point& topLeft, const Point& bottomRight);
};

#endif