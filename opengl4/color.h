#pragma once
#include <string>
struct color {
	float r, g, b;
	color(float _r, float _g, float _b) : r(_r), g(_g), b(_b) {};
	color(float white) : color(white, white, white) {}
	color():color(0.0f, 0.0f, 0.0f) {};
};
std::string toString(color c);