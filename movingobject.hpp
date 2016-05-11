#ifndef MOVINGOBJECT_HPP
#define MOVINGOBJECT_HPP

#include "graphicsobject.hpp"

#include <coordinate.h>

#define MOVE_INCREMENT 3
#define NUM_LIVES_START 3

class MovingObject : public GraphicsObject
{
protected:
	Coordinate c;

public:
	MovingObject();

	void setCoordinate(const Coordinate& c) { this->c = c; }
	Coordinate getCoordinate() const { return c; }

	virtual void draw() = 0;
	virtual void update() = 0;
};

#endif 