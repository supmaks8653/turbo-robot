#pragma once
#include "health.h"
#include "drawable.h"
#include "helperFunctions.h"
#include "offsetDrawable.h"
#include "pathing.h"
class entity {
	pathing path;
	gstat visionRange;
	gstat attackRange;
	gstat speed;
	gstat power;
	health hp;
	drawable entityDrawable;
	gstat size;
	point pos;
	drawable healthCircle;
	drawable healthDrawable;
	float prevPercent;
	float getPercentHealth();
public:
	entity(float maxHealth, float baseSpeed, float basePower, float x, float y, std::vector<singleDrawable> drawables,
		float size, int zOrder, float visionRange, float attackRange);
	entity(std::vector<singleDrawable> drawables, float x, float y);
	void reCreateHealth();
	drawable getDrawable();
	float distanceNS(entity e);
	bool isDead();
	void getDamaged(float damage);
	void getHealed(float heal);
	float getPower();
	point getPos();
	void printSpeed();
	void printPower();
	void printHealth();
	void printSize();
	void printPos();
	float getHealth();
	offsetDrawable getOffsetDrawable();
	void chooseAndMove(std::vector<point> targets);
};
const float DEFAULT_HEALTH = 900.0f;
const float DEFAULT_POWER = 2.0f;
const float DEFAULT_SPEED = 0.01f;
const float DEFAULT_VISION_RANGE = 1.0f;
const float DEFAULT_ATTACK_RANGE = 0.1f;
const float DEFAULT_HEALTH_HEIGHT = 0.4f;
const float DEFAULT_HEALTH_SCALE = 10.0f;
const float DEFAULT_SIZE = 0.2f;
const color DEFAULT_HEALTH_CIRCLE_COLOR = color(0.5f, 0.5f, 0.5f);
const color DEFAULT_HEALTH_COLOR = color(0.9f, 0.1f, 0.1f);
std::vector<singleDrawable> createResized(std::vector<singleDrawable> startDrawables, float size);