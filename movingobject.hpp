#ifndef MOVINGOBJECT_HPP
#define MOVINGOBJECT_HPP

#include "graphicsobject.hpp"
#include "point.hpp"
#include "velocity.hpp"

#define MOVE_INCREMENT 3
#define NUM_LIVES_START 3

class MovingObject : public GraphicsObject
{
protected:
public:
	MovingObject();

	virtual void draw() = 0;
	virtual void update() = 0;
};

#endif 