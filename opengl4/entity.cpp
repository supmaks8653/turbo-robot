#include "entity.h"
#include "printer.h"

entity::entity(float maxHealth, float baseSpeed, float basePower, float x, float y, std::vector<singleDrawable> drawables,
	float _size, int zOrder, float _visionRange, float _attackRange) :
	path(pathing()),
	visionRange(_visionRange),
	attackRange(_attackRange),
	hp(maxHealth),
	speed(baseSpeed),
	power(basePower),
	entityDrawable(createResized(drawables,_size),clampZOrder(zOrder)),
	size(_size),
	pos(x, y),
	healthCircle(createResized(drawableCreator::createHealthDrawable(DEFAULT_HEALTH_CIRCLE_COLOR),_size/DEFAULT_HEALTH_SCALE),
		clampZOrder(zOrder)),
	healthDrawable(createResized(drawableCreator::createHealthDrawable(DEFAULT_HEALTH_COLOR,1.0f), _size/DEFAULT_HEALTH_SCALE),
		clampZOrder(zOrder))
{
	prevPercent = 1.0f;
}
std::vector<singleDrawable> createResized(std::vector<singleDrawable> startDrawables, float size) {
	std::vector<singleDrawable> resizedDrawables = std::vector<singleDrawable>();
	for (int i = 0; i < startDrawables.size(); i++) {
		singleDrawable sd = startDrawables[i];
		resizedDrawables.push_back(singleDrawable{ sd.p.mult(size), sd.c });
	}
	return resizedDrawables;
}

//void entity::drawEntity() {
//	entityDrawable.draw(pos);
//	float csize = size.getValue() * 1.5f;
//	point healthPos = pos.add(point(csize, csize));
//	healthDrawable.drawHealth(healthPos);
//	healthCircle.drawHealth(healthPos);
//}

float entity::distanceNS(entity e) {
	return pos.distanceNS(e.pos);
}

entity::entity(std::vector<singleDrawable> drawables, float x, float y) : entity(DEFAULT_HEALTH, DEFAULT_SPEED, DEFAULT_POWER,
	x,y,createResized(drawables,DEFAULT_SIZE), DEFAULT_SIZE,0.0f, DEFAULT_VISION_RANGE, DEFAULT_ATTACK_RANGE) {}

drawable entity::getDrawable() {
	return entityDrawable;
}
bool entity::isDead() {
	return hp.isDead();
}

void entity::getDamaged(float damage) {
	hp.damage(damage);
	float newPercent = getPercentHealth();
		prevPercent = newPercent;
		reCreateHealth();
}
void entity::reCreateHealth() {
	float percent = getPercentHealth();
	healthDrawable = createResized(drawableCreator::createHealthDrawable(DEFAULT_HEALTH_COLOR, percent), size.getBase() / DEFAULT_HEALTH_SCALE);
	std::cout << "Health " << percent << '\n';
}
void entity::getHealed(float heal) {
	hp.heal(heal);
}
float entity::getPower() {
	return power.getValue();
}
void entity::printSpeed() {
	std::cout << "speed: ";
	printer:: print(speed);
}
void entity::printHealth() {
	std::cout << "health: ";
	printer::print(hp);
}
void entity::printSize() {
	std::cout << "size: ";
	printer::print(size);
}
void entity::printPower() {
	std::cout << "power: ";
	printer::print(power);
}
void entity::printPos() {
	std::cout << "pos: ";
	printer::print(pos);
}
offsetDrawable entity::getOffsetDrawable() {
	float currentSize = size.getValue() * DEFAULT_HEALTH_HEIGHT;
	point offset = pos.add(point(0.0f, currentSize));
	return offsetDrawable(pos,offset, entityDrawable, healthCircle, healthDrawable);
}
float entity::getPercentHealth() {
	return hp.getPercentHealth();
}
float entity::getHealth() {
	return hp.getCurrent();
}
void entity::chooseAndMove(std::vector<point> targets) {
	std::cout << "speed " << speed.getValue() << '\n';
	point movement = path.getNewPos(targets, pos, speed.getValue(), visionRange.getValue(), attackRange.getValue());
	pos = movement;
}
point entity::getPos() {
	return pos;
}