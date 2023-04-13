#pragma once
#include "statChange.h"
class gstat {
protected:
	statChange change;
public:
	float baseValue;
	gstat(float baseValue);
	void changeFlat(float value);
	void changePercent(float value);
	float getValue();
	float getBase();
};