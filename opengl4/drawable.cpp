#include "drawable.h"

drawable::drawable(std::vector<singleDrawable> _drawables, int _zOrder) : drawables(_drawables), zOrder(_zOrder) {};

drawable::drawable(std::vector<singleDrawable> _drawables) :
	drawable(_drawables, 0)
{}

void drawable::draw(point offset) {
	draw(offset, GL_POLYGON);
}

void drawable::setColor(int index) {
	color c = drawables[index].c;
	setColor(c);
}
void drawable::vertex(int index, point offset) {
	point p = drawables[index].p;
	vertex(p.add(offset));
}

std::vector<singleDrawable> drawable::getDrawables() {
	return drawables;
}

int drawable::getZOrder() {
	return zOrder;
}

void drawable::drawHealth(point offset) {
	draw(offset, GL_LINE_LOOP);
}
void drawable::draw(point offset, GLenum mode) {
	glBegin(mode);
	for (int i = 0; i < drawables.size(); i++) {
		setColor(i);
		vertex(i, offset);
	}
	glEnd();
}
void drawable::setColor(color c) {
	glColor3f(c.r, c.g, c.b);
}
void drawable::vertex(point p) {
	glVertex2f(p.getX(), p.getY());
}
void drawable::draw() {
	draw(point(), GL_LINE_STRIP);
}