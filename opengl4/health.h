#pragma once
#include "stat.h"
const bool KILLED = true;
const bool NOT_KILLED = false;
class health{
	gstat values;
	bool dead;
	float current;
public:
	health(float maxHealth);
	void heal(float value);
	bool damage(float value);
	float getCurrent();
	float getMax();
	bool isDead();
	void printStat();
	float getPercentHealth();
};