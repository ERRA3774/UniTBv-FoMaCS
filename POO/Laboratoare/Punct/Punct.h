#pragma once

#include "iostream"
#include "math.h"
class Punct
{
private:
	float x, y;

public:
	Punct();
	Punct(float X, float Y);
	void init(float X, float Y);
	float getX();
	float getY();
	void setX(float X);
	void setY(float X);
	float dist(Punct p);
	float norm();
	Punct amplif(float s);
	Punct suma(Punct p);
	Punct difer(Punct p);
	Punct suma(float s);
	Punct impart(float s);
	Punct operator*(float s);
	Punct operator*(Punct p);
	Punct operator-(Punct p);
	Punct operator+(float s);
	Punct operator+(Punct p);
	float operator!();
	friend Punct operator*(float s, Punct p);
	friend Punct operator+(float s, Punct p);
	friend std::ostream& operator<<(std::ostream& fl, Punct p);
	friend std::istream& operator>>(std::istream& fl, Punct& p);
	~Punct();
};