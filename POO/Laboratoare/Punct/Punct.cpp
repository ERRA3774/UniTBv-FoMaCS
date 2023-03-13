#include "Punct.h"

Punct::Punct()
{
}

Punct::Punct(float X, float Y)
{
	x = X;
	y = Y;
}

void Punct::init(float X, float Y)
{
	x = X;
	y = Y;
}

float Punct::getX()
{
	return x;
}

float Punct::getY()
{
	return y;
}

void Punct::setX(float X)
{
	x = X;
}

void Punct::setY(float Y)
{
	y = Y;
}

Punct Punct::amplif(float s)
{
	return Punct(x * s, y * s);
}

float Punct::dist(Punct p)
{
	float dx = x - p.x;
	float dy = y - p.y;
	return sqrt(dx * dx + dy * dy);
}

float Punct::norm()
{
	return sqrt(x * x + y * y);
}

Punct Punct::suma(Punct p)
{
	return Punct(x + p.x, y + p.y);
}

Punct Punct::difer(Punct p)
{
	return Punct(x - p.x, y - p.y);
}

Punct Punct::suma(float s)
{
	return Punct(x + s, y);
}

Punct Punct::impart(float s)
{
	return Punct(x / s, y / s);
}

Punct Punct::operator*(float s)
{
	return Punct(x * s, y * s);
}

Punct Punct::operator*(Punct p)
{
	return Punct(x * p.x, y * p.y);
}

Punct Punct::operator-(Punct p)
{
	return Punct(x - p.x, y - p.y);
}

Punct Punct::operator+(float s)
{
	return Punct(x + s, y + s);
}

Punct Punct::operator+(Punct p)
{
	return Punct(x + p.x, y + p.y);
}

float Punct::operator!()
{
	return sqrt(x * x + y * y);
}

Punct::~Punct()
{
}

Punct operator*(float s, Punct p)
{
	return p * s;
}

Punct operator+(float x, Punct p)
{
	return Punct(x + p.x, p.y);
}

std::ostream& operator<<(std::ostream& fl, Punct p)
{
	return fl << "(" << p.x << " " << p.y << ")";
}

std::istream& operator>>(std::istream& fl, Punct& p)
{
	return fl >> p.x >> p.y;
}
