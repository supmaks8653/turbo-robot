#include "health.h"
#include "../helpers/printer.h"

health::health(float max) : values(max) {
	current = max;
	dead = false;
}

void health::heal(float value) {
	current += value;
	if (current > values.baseValue) current = values.baseValue;
}
bool health::damage(float value) {
	
	current -= value;
	if (current <= 0) {
		current = 0.0f;
		dead = true;
		return KILLED;
	}
	return NOT_KILLED;
}
float health::getCurrent() {
	return current;
}
float health::getMax() {
	return values.getValue();
}
bool health::isDead() {
	return dead;
}
void health::printStat() {
	std::cout << "values: ";
	printer::print(values);
}
float health::getPercentHealth() {
	return current / getMax();
}