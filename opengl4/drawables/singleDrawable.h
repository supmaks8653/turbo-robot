#pragma once

#include "point.h"
#include "color.h"
struct singleDrawable {
	point p;
	color c;
	singleDrawable(point _p, color _c) : p(_p), c(_c) {}
	singleDrawable() : singleDrawable(point(), color()) { }
};