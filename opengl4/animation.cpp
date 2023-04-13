#include "animation.h"
animation::animation(point _start, point _end, color _c) {
	start = _start;
	end = _end;
	c = _c;
}
void animation::drawFrame(int frame) {
	//should always be empty
}