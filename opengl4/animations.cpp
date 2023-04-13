#include "animations.h"
void testDraw::drawFrame(int frame) {
	if (frame > MAX_FRAME) {
		ended = true;
		return;
	}
	if (frame <= 0) return;
	float coeff = MAX_FRAME / float(frame < FRAME_SKIP ? FRAME_SKIP : frame);
	coeff = sqrt(coeff);
	point sideStep = direction.mult(DEFAULT_SIDES_SIZE * coeff);
	point leftPoint = point(sideStep.getY(), -sideStep.getX());
	point rightPoint = leftPoint.unaryMinus();
	leftPoint = leftPoint.add(start);
	rightPoint = rightPoint.add(start);
	point endPoint = start.add(singleStep.mult(frame));
	point leftEnd = leftTargetPoint.add(endPoint);
	point rightEnd = rightTargetPoint.add(endPoint);
	std::vector<point> points = std::vector<point>();
	points.push_back(leftPoint);
	points.push_back(start);
	points.push_back(leftEnd);
	drawable toDraw = drawable(drawableCreator::createBezier(points, c));
	toDraw.draw();
	points.clear();
	points.push_back(rightPoint);
	points.push_back(start);
	points.push_back(rightEnd);
	toDraw = drawable(drawableCreator::createBezier(points, c));
	toDraw.draw();
}
testDraw::testDraw(float ts, point s, point e, color c) :animation(s, e, c) {
	targetSize = ts;
	direction = e.minus(s);
	singleStep = direction.div(MAX_FRAME);
	point sideStep = direction.normalize().mult(targetSize);
	leftTargetPoint = point(sideStep.getY(), -sideStep.getX());
	rightTargetPoint = leftTargetPoint.unaryMinus();
}