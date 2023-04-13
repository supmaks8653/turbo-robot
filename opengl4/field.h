#pragma once
#include <stack>
#include "drawables/offsetDrawable.h"
#include "entity.h"
class field {
	std::vector<std::stack<offsetDrawable>> drawStack;
	std::vector<entity> enemies;
	entity player;
	point playerTarget;
	void placeDrawableInStack(offsetDrawable d);
	void removeDead();
	void damage();
	void moveEnemies();
	void draw();
	void drawWithReturn();
	void drawWithoutReturn();
	void createDrawStack();
	bool playerTargetExists = false;
	std::vector<point> getPlayerPosition();
	std::vector<point> getPlayerTargetPosition();
	void movePlayer();
public:
	field(entity player);
	void update();
	void setPlayerTarget(point p);
	void addEnemy(entity enemy);
	void printPlayer();
	void printEnemies();
};