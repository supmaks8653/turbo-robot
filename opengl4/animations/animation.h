#pragma once
#include "../drawables/drawable.h"
class animation {
protected:
	color c;
	point start, end;
	bool ended = false;
public:
	animation(point s, point e, color c);
	static void drawFrame(int frame);
};