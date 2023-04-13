#pragma once
#include <iostream>
#include "field.h"
class printer {
public:
	static void print(drawable d);
	static void print(singleDrawable sd);
	static void print(color c);
	static void print(point p);
	static void print(gstat s);
	static void print(statChange sc);
	static void print(entity e);
	static void print(health h);
	static void print(field f);
};