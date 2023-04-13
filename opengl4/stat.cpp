#include "stat.h"

gstat::gstat(float _baseValue) :
	baseValue(_baseValue) 
{}

void gstat::changeFlat(float value) {
	change.flatIncrease += value;
}
void gstat::changePercent(float value) {
	change.percentIncrease += value;
}

float gstat::getValue() {
	return (baseValue + change.flatIncrease / 2.0f) * change.percentIncrease;
}
float gstat::getBase() {
	return baseValue;
}