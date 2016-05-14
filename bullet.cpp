#include "bullet.hpp"

Bullet::Bullet(SDL_Renderer *r, const Point& p)
{
	this->renderer = r;
	this->p = p;
	v = Velocity(DEFAULT_DX, DEFAULT_DY);
}

void Bullet::draw()
{
	//Remember the old color...
	SDL_Color oc;
	SDL_GetRenderDrawColor(renderer, &oc.r, &oc.g, &oc.b, &oc.a);

	// cout << "Old color:\n";
	// displayColor(oc);

	// cout << "Bullet color:\n";
	// displayColor(color);
	// cout << "\n";
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawLine(renderer, 
		p.getX(), 
		p.getY(), 
		p.getX(), 
		p.getY() + 10
	);



	//Reset the color back to how it was
	SDL_SetRenderDrawColor(renderer, oc.r, oc.g, oc.b, oc.a);
	// SDL_RenderPresent(renderer);
}

void Bullet::update()
{
	p -= v;
	// cout << p << std::endl;
}

bool Bullet::outOfBounds(const Point& topLeft, const Point& bottomRight)
{
	// cout << "TOPLEFT: " << topLeft << std::endl;
	// cout << "BOTRIGHT: " << bottomRight << std::endl;
	// cout << "\t" << p << std::endl;
	int x = p.getX();
	int y = p.getY();

	int tlX = topLeft.getX() + 1;
	int tlY = topLeft.getY() - 1;

	int brX = bottomRight.getX() - 1;
	int brY = bottomRight.getY() + 1;

	if (x < tlX || x > brX)
	{
		cout << "A\n";
		return true;
	}
	if (y < tlY || y > brY)
	{
		cout << "B: y = " << y << "; brY: " << brY << "; tlY: " << tlY << std::endl;
		return true;
	}

	return false;
}