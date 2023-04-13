#include "printer.h"

void printer::print(drawable d) {
	std::cout << "drawable:\n";
	std::vector<singleDrawable> drawables = d.getDrawables();
	for (singleDrawable sd : drawables) {
		print(sd);
	}
}
void printer::print(singleDrawable sd) {
	std::cout << "single drawable:\n";
	print(sd.p);
	print(sd.c);
}
void printer::print(color c) {
	std::cout << "color ( " << c.r << " ; " << c.g << " ; " << c.b << " )\n";
}
void printer::print(point p) {
	std::cout << "point ( " << p.getX() << " ; " << p.getY() << " )\n";
}
void printer::print(gstat s) {
	std::cout << "stat (base: " << s.getBase() << " ;stat change:\n";
	std::cout << " )\n";
}
void printer::print(statChange sc) {
	std::cout << "stat change (flat: " << sc.flatIncrease << " ;percent: " << sc.percentIncrease << " )\n";
}
void printer::print(entity e) {
	std::cout << "entity (";
	e.printSpeed();
	e.printPower();
	e.printHealth();
	e.printSize();
	e.printPos();
	std::cout << ")\n";
}
void printer::print(health h) {
	std::cout << "health (";
	h.printStat();
	std::cout << "dead: " << h.isDead() << "\ncurrent: " << h.getCurrent() << "\n)\n";
}
void printer::print(field f) {
	std::cout << "field (\nplayer: ";
	f.printPlayer();
	f.printEnemies();
	std::cout << ")\n";
}