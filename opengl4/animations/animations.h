#pragma once
#include "animation.h"
#include "../drawables/drawableCreators.h"
class testDraw : animation {
	float targetSize;
	point singleStep;
	point leftTargetPoint, rightTargetPoint;
	point direction;
public:
	testDraw(float ts, point s, point e ,color c);
	static const int MAX_FRAME = 1000;
	static const int FRAME_SKIP = 100;
	const float DEFAULT_SIDES_SIZE = 0.05f;
	void drawFrame(int frame);
};