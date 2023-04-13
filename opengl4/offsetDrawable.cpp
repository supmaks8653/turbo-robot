#include "offsetDrawable.h"

offsetDrawable::offsetDrawable(point _offset, point _healthOffset, drawable _d, drawable _healthCircle, drawable _health) :offset(_offset), healthOffset(_healthOffset), d(_d), healthCircle(_healthCircle), health(_health) {}
void offsetDrawable::drawFirst() {
	d.draw(offset);
}
void offsetDrawable::drawSecond() {
	healthCircle.draw(healthOffset);
	health.draw(healthOffset);
	healthCircle.drawHealth(healthOffset);
}
int offsetDrawable::getZOrder() {
	return d.getZOrder();
}