#include "field.h"
#include "helpers/printer.h"
field::field(entity _player) : player(_player), enemies(std::vector<entity>()), drawStack(std::vector<std::stack<offsetDrawable>>(11)) {

}

void field::draw() {
	drawWithReturn();
	drawWithoutReturn();
}
void field::drawWithReturn() {
	for (int i = 0; i < drawStack.size();i++) {
		std::vector<offsetDrawable> stackElements = std::vector<offsetDrawable>();
		while (!drawStack[i].empty()) {
			offsetDrawable top = drawStack[i].top();
			drawStack[i].pop();
			stackElements.push_back(top);
			top.drawFirst();
		}
		for (int i = stackElements.size() - 1; i > -1; i--) drawStack[i].push(stackElements[i]);
	}
}
void field::drawWithoutReturn() {
	for (int i = 0; i < drawStack.size(); i++) {
		while (!drawStack[i].empty()) {
			offsetDrawable top = drawStack[i].top();
			drawStack[i].pop();
			top.drawSecond();
		}
	}
}
void field::createDrawStack() {
	placeDrawableInStack(player.getOffsetDrawable());
	for (entity e : enemies) placeDrawableInStack(e.getOffsetDrawable());
}
void field::placeDrawableInStack(offsetDrawable d) {
	int order = d.getZOrder();
	int index = order - Z_ORDER_MIN;
	drawStack[index].push(d);
}
void field::removeDead() {
	std::vector<entity> newEntities = std::vector<entity>();
	for (int i = enemies.size() - 1; i > -1; i--) {
		entity current = enemies[i];
		if (!current.isDead()) newEntities.push_back(current);
	}
	enemies = newEntities;
}
void field::update() {
	damage();
	removeDead();
	moveEnemies();
	movePlayer();
	createDrawStack();
	draw();
}
void field::damage() {
	for (int i = 0; i < enemies.size(); i++) {
		 enemies[i].getDamaged(player.getPower());
		 float range = enemies[i].getRange();
		 range *= range;
		 if (enemies[i].getPos().distanceNS(player.getPos()) <= range) {
			 player.getDamaged(enemies[i].getPower() / 10.0f);
		 }
	}
}

void field::addEnemy(entity enemy) {
	enemies.push_back(enemy);
}
void field::printPlayer() {
	std::cout << "player: ";
	printer::print(player);
}
void field::printEnemies() {
	std::cout << "amount of enemies: " << enemies.size() << "\nenemies: {";
	for (entity e : enemies) printer::print(e);
	std::cout << "}\n";
}
std::vector<point> field::getPlayerPosition() {
	std::vector<point> result = std::vector<point>();
	result.push_back(player.getPos());
	return result;
}
void field::moveEnemies() {
	std::vector<point> targets = getPlayerPosition();
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i].chooseAndMove(targets);
	}
}
void field::setPlayerTarget(point p) {
	playerTarget = p;
	playerTargetExists = true;
}
std::vector<point> field::getPlayerTargetPosition() {
	std::vector<point> result = std::vector<point>();
	result.push_back(playerTarget);
	return result;
}
void field::movePlayer() {
	if(playerTargetExists) player.chooseAndMove(getPlayerTargetPosition());
}