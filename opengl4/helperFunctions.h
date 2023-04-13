#pragma once
const int Z_ORDER_MIN = -5;
const int Z_ORDER_MAX = 5;
int clamp(int value, int min, int max);
int clampZOrder(int value);