#ifndef MOVINGOBJECT_HPP
#define MOVINGOBJECT_HPP

#include "graphicsobject.hpp"
#include "point.hpp"

#define MOVE_INCREMENT 3
#define NUM_LIVES_START 3

class MovingObject : public GraphicsObject
{
protected:
	Point p;

public:
	MovingObject();

	void setPoint(const Point& p) { this->p = p; }
	Point getPoint() const { return p; }

	virtual void draw() = 0;
	virtual void update() = 0;
};

#endif 