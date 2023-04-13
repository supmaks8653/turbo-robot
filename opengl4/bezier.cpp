#include "bezier.h"

point bezier::partPoint(point start, point end, float part) {
	point direction = end.minus(start);
	point toAdd = direction.mult(part);
	return start.add(toAdd);
}
point bezier::getPoint(std::vector<point> points, float part) {
	if (points.size() == 1) return points[0];
	std::vector<point> nextPoints = std::vector<point>(points.size() - 1);
	for (int i = 0; i < nextPoints.size(); i++) nextPoints[i] = partPoint(points[i], points[i + 1], part);
	return getPoint(nextPoints, part);
}