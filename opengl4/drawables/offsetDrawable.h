#pragma once
#include "drawable.h"
class offsetDrawable {
	point offset;
	point healthOffset;
	drawable healthCircle;
	drawable health;
	drawable d;
public:
	offsetDrawable(point p, point healthP, drawable d, drawable hpc, drawable hp);
	void drawFirst();
	void drawSecond();
	int getZOrder();
};