#include "lineobject.hpp"

LineObject::LineObject(SDL_Renderer* r, const Point& startPoint, const Point& endPoint)
{
	this->p = startPoint;
	this->endPoint = endPoint;
	this->renderer = r;
}

void LineObject::draw()
{
	//Remember the old color...
	SDL_Color oc;
	SDL_GetRenderDrawColor(renderer, &oc.r, &oc.g, &oc.b, &oc.a);

	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawLine(renderer, 
		p.getX(), 
		p.getY(), 
		endPoint.getX(), 
		endPoint.getY()
	);

	//Reset the color back to how it was
	SDL_SetRenderDrawColor(renderer, oc.r, oc.g, oc.b, oc.a);
	// SDL_
}

void LineObject::update()
{

}