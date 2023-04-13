#pragma once

#include <iostream>
class point {
protected:
	float x, y;
public:
	point();
	float getX();
	float getY();
	point(float x, float y);
	point mult(float n);
	point div(float n);
	point add(point p);
	point unaryMinus();
	point minus(point p);
	float lengthNS();
	float length();
	point normalize();
	float distanceNS(point p);
};