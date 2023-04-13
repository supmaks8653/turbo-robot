#pragma once
#include "singleDrawable.h"
#include <vector>
#include "bezier.h"
class drawableCreator {
	static point getCirclePoint(int step);
public:
	static std::vector<singleDrawable> createPlayerDrawable();
	static std::vector<singleDrawable> createEnemyDrawable();
	static std::vector<singleDrawable> createHealthDrawable(color c);
	static std::vector<singleDrawable> createHealthDrawable(color c, float percent);
	static std::vector<singleDrawable> createBezier(std::vector<point> points, float precision, color c);
	static std::vector<singleDrawable> createBezier(std::vector<point> points, color c);
};
const float DEFAULT_PRECISION = 0.01f;
const int steps = 180;
const float angleStepForCircles = 3.1415f * 2.0f / steps;