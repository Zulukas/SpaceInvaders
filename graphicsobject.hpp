#ifndef GRAPHICSOBJECT_HPP
#define GRAPHICSOBJECT_HPP

class GraphicsObject
{
protected:
public:
	GraphicsObject() {}

	virtual void draw() = 0;
	virtual void update() = 0;
};

#endif