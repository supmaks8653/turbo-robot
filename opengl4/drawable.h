#pragma once
#include "drawableCreators.h"
#include <GL/freeglut.h>
class drawable {
	int zOrder;
	std::vector<singleDrawable> drawables;
	void setColor(int i);
	void vertex(int i, point offset);
public:
	drawable(std::vector<singleDrawable> drawables, int zOrder);
	drawable(std::vector<singleDrawable> drawables);
	void draw();
	void draw(point offset, GLenum mode);
	void draw(point offset);
	void drawHealth(point offset);
	std::vector<singleDrawable> getDrawables();
	int getZOrder();
	static void setColor(color c);
	static void vertex(point p);
};