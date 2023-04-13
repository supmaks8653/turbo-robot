#pragma once
#include "../baseClasses/point.h"
#include <vector>
class bezier {
	static point partPoint(point start, point end, float part);
public:
	static point getPoint(std::vector<point> points, float part);
};