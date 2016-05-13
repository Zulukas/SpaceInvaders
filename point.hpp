#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

#include "velocity.hpp"

class Point
{
private:
	int x;
	int y;

	int addX(const int val) { return x + val; }
	int addY(const int val) { return y + val; }

	int subX(const int val) { return x - val; }
	int subY(const int val) { return y - val; }
public:
	Point() { x = 0; y = 0; }
	Point(const int x, const int y) { this->x = x; this->y = y; }
	Point(const Point& p) { this->x = p.x; this->y = p.y; }

	void setX(const int x) { this->x = x; }
	void setY(const int y) { this->y = y; }

	int getX() const { return x; }
	int getY() const { return y; }

	Point operator + (const Point& p)
	{
		return Point(addX(p.getX()), addY(p.getY()));
	}

	Point operator + (const Velocity& v)
	{
		return Point(addX(v.getDX()), addY(v.getDY()));
	}

	Point operator - (const Point& p)
	{
		return Point(subX(p.getX()), subY(p.getY()));
	}

	Point operator - (const Velocity& v)
	{
		return Point(subX(v.getDX()), subY(v.getDY()));
	}

	void operator += (const Point& p)
	{
		this->x += p.getX();
		this->y += p.getY();
	}

	void operator += (const Velocity& v)
	{
		this->x += v.getDX();
		this->y += v.getDY();
	}

	void operator -= (const Point& p)
	{
		this->x -= p.getX();
		this->y -= p.getY();
	}

	void operator -= (const Velocity& v)
	{
		this->x -= v.getDX();
		this->y -= v.getDY();
	}
};

inline std::ostream& operator << (std::ostream& out, const Point& p)
{
	out << "(" << p.getX() << ", " << p.getY() << ")";

	return out;
}

#endif