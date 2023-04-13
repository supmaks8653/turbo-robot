#pragma once
#include "point.h"
#include "stat.h"
#include <vector>
class pathing {
	point target;
	static point getPathTowards(point start, point end, float speed, float range);
	void chooseTarget(std::vector<point> targets, point pos, float range);
public:
	point getNewPos(std::vector<point> targets, point pos, float speed, float range, float atkrange);
};