#ifndef GRAPHICSOBJECT_HPP
#define GRAPHICSOBJECT_HPP

#include "point.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_pixels.h>
#include <vector>
#include <iostream>

using std::cout;

const SDL_Color WHITE = {255, 255, 255, 0};
const SDL_Color BLACK = {0, 0, 0};
const SDL_Color RED = {255, 0, 0};
const SDL_Color GREEN = {0, 255, 0};
const SDL_Color BLUE = {0, 0, 255};

class GraphicsObject
{
protected:
	Point p;
	SDL_Color color;	
	SDL_Renderer* renderer;

public:
	GraphicsObject()
	{
		renderer = nullptr;
		color = WHITE;
		p = Point();
	}
	
	GraphicsObject(SDL_Renderer* renderer) 
	{
		this->renderer = renderer; 
		color = WHITE;
		p = Point();
	}

	GraphicsObject(SDL_Renderer* renderer, SDL_Color color, Point p)
	{
		this->renderer = renderer;
		this->color = color;
		this->p = p;
	}

	virtual void draw() = 0;
	virtual void update() = 0;

	virtual Point getPoint() const { return p; }
	virtual void setPoint(const Point& p) { this->p = p; }

	virtual void setColor(const SDL_Color& color) { this->color = color; }
	virtual SDL_Color getColor() const { return color; }

	virtual bool outOfBounds(const Point& topLeft, const Point& bottomRight) { return false; }
};

inline void displayColor(const SDL_Color& color)
{
	cout << "{" << (int)color.r << ", " << (int)color.g << ", " << (int)color.b << "}\n";	
}

#endif