#pragma once
#include <stack>
#include "offsetDrawable.h"
#include "entity.h"
class field {
	std::vector<std::stack<offsetDrawable>> drawStack;
	std::vector<entity> enemies;
	entity player;
	void placeDrawableInStack(offsetDrawable d);
	void removeDead();
	void damage();
	void moveEnemies();
	void draw();
	void drawWithReturn();
	void drawWithoutReturn();
	void createDrawStack();
	std::vector<point> getPlayerPosition();
public:
	field(entity player);
	void update();
	void addEnemy(entity enemy);
	void printPlayer();
	void printEnemies();
};