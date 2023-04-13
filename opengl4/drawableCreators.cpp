#include "drawableCreators.h"
std::vector<singleDrawable> drawableCreator::createPlayerDrawable() {
	point p1 = point(-1.0f, 1.0f);
	point p2 = point(1.0f, 1.0f);
	point p3 = point(1.0f, -1.0f);
	point p4 = point(-1.0f, -1.0f);
	color c = color(0.0f, 0.5f, 0.0f);
	std::vector<singleDrawable> drawables = std::vector<singleDrawable>();
	drawables.push_back(singleDrawable(p1, c));
	drawables.push_back(singleDrawable(p2, c));
	drawables.push_back(singleDrawable(p3, c));
	drawables.push_back(singleDrawable(p4, c));
	return drawables;
}
std::vector<singleDrawable> drawableCreator::createEnemyDrawable() {
	point p1 = point(-1.0f, 1.0f);
	point p2 = point(1.0f, 1.0f);
	point p3 = point(0.0f, -1.0f);
	color c = color(1.0f, 0.0f, 0.0f);
	std::vector<singleDrawable> drawables = std::vector<singleDrawable>();
	drawables.push_back(singleDrawable(p1, c));
	drawables.push_back(singleDrawable(p2, c));
	drawables.push_back(singleDrawable(p3, c));
	return drawables;
}
std::vector<singleDrawable> drawableCreator::createHealthDrawable(color c) {
	std::vector<singleDrawable> result = std::vector<singleDrawable>();
	for (int i = 0; i < steps; i++) result.push_back(singleDrawable(getCirclePoint(i), c));
	return result;
}
std::vector<singleDrawable> drawableCreator::createHealthDrawable(color c,float percentFilled) {
	float percentEmpty = 1.0f - percentFilled;
	int skip = round(steps * percentEmpty);
	if (skip == 0) return createHealthDrawable(c);
	std::vector<singleDrawable> result = std::vector<singleDrawable>();
	if(skip<steps) result.push_back(singleDrawable(point(), c));
	for(int i = skip;i<steps+1;i++) result.push_back(singleDrawable(getCirclePoint(i), c));
	return result;
}
point drawableCreator::getCirclePoint(int step) {
	float angle = angleStepForCircles * step;
	return point(cos(angle), sin(angle));
}
std::vector<singleDrawable> drawableCreator::createBezier(std::vector<point> points, float precision, color c) {
	std::vector<singleDrawable> result = std::vector<singleDrawable>();
	for (float i = 0.0f; i <= 1.0f; i += precision) {
		result.push_back(singleDrawable(bezier::getPoint(points, i), c));
	}
	return result;
}
std::vector<singleDrawable> drawableCreator::createBezier(std::vector<point> points, color c) {
	return createBezier(points, DEFAULT_PRECISION, c);
}