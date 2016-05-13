#ifndef VELOCITY_HPP
#define VELOCITY_HPP

class Velocity
{
private:
	int dX, dY;
public:
	Velocity() {dX = 0; dY = 0; }
	Velocity(const int dX, const int dY) { this->dX = dX; this->dY = dY; }
	Velocity(const Velocity& v) { this->dX = v.dX; this->dY = v.dY; }

	void setDX(const int dX) { this->dX = dX; }
	void setDY(const int dY) { this->dY = dY; }

	int getDX() const { return dX; }
	int getDY() const { return dY; }
};

#endif