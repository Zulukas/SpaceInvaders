#ifndef VELOCITY_HPP
#define VELOCITY_HPP

class Velocity
{
private:
	int dX, dY;
public:
	Velocity();
	Velocity(int dX, int dY);

	void setDX(const int dX) { this->dX = dX; }
	void setDY(const int dY) { this->dY = dY; }

	int getDX() const { return dX; }
	int getDY() const { return dY; }
};

#endif