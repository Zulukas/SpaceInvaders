#ifndef LINEOBJECT_HPP
#define LINEOBJECT_HPP

#include "graphicsobject.hpp"

class LineObject : public GraphicsObject
{
private:
	Point endPoint;
public:
	LineObject(SDL_Renderer* r, const Point& startPoint, const Point& endPoint);

	void draw();
	void update();

	
};

#endif