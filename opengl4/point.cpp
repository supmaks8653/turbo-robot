#include "point.h"

point::point(float _x, float _y) : x(_x), y(_y) {

}
point::point() : x(0.0f), y(0.0f) {}

float point::getX() {
	return x;
}
float point::getY() {
	return y;
}
point point::div(float n) {
	return mult(1.0f / n);
}
point point::add(point p) {
	return point(x + p.x, y + p.y);
}
point point::unaryMinus() {
	return point(-x, -y);
}
point point::minus(point p) {
	return add(p.unaryMinus());
}
float point::lengthNS() {
	return x * x + y * y;
}
float point::distanceNS(point p) {
	return minus(p).lengthNS();
}
float point::length() {
	return sqrt(lengthNS());
}
point point::mult(float n){
	return point(n * x, n * y);
}
point point::normalize() {
	return div(length());
}