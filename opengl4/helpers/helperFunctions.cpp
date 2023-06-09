#include "helperFunctions.h"
int clamp(int value, int min, int max) {
	if (value >= max) return max;
	if (value <= min) return min;
	return value;
}
int clampZOrder(int value) {
	return clamp(value, Z_ORDER_MIN, Z_ORDER_MAX);
}