#include "pathing.h"
#include "printer.h"
point pathing::getPathTowards(point start, point end, float speed, float range) {
	point direction = end.minus(start);
	point norm = direction.normalize();
	point movePerTick = norm.mult(range);
	if (direction.lengthNS() <= movePerTick.lengthNS()) return point();
	point needsDirection = direction.minus(norm.mult(range));
	float needsToMove = needsDirection.lengthNS();
	std::cout << "Needs to move " << needsToMove << '\n';
	float speedSquared = speed * speed;
	if (needsToMove <= speedSquared) {
		return needsDirection;
	}
	point result = norm.mult(speed);
	return result;
}
void pathing::chooseTarget(std::vector<point> targets, point pos, float range) {
	float rangeSquared = range; //vision
	bool first = true;
	float prevDistance;
	rangeSquared *= rangeSquared;
	for (point i : targets) {
		float thisDistance = i.distanceNS(pos);
		if (thisDistance <= rangeSquared) {
			if (first) {
				prevDistance = thisDistance;
				target = i;
				first = false;
			}
			else if (thisDistance < prevDistance) {
				prevDistance = thisDistance;
				target = i;
			}
		}
	}
}
point pathing::getNewPos(std::vector<point> targets, point pos, float speed, float range, float atkrange) {
	chooseTarget(targets, pos, range);
	return pos.add(getPathTowards(pos, target, speed, atkrange));
}