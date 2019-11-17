#include "Coordinates.h"
Coordinates::Coordinates() : x(0), y(0) {}
Coordinates::Coordinates(int x, int y) : x(x), y(y) {}
Coordinates::Coordinates(const Coordinates& obj) : x(obj.x), y(obj.y) {}
Coordinates& Coordinates::operator =(const Coordinates& obj) {
	x = obj.x;
	y = obj.y;
	return *this;
}
int Coordinates::get_x() const {
	return x;
}
int Coordinates::get_y() const {
	return y;
}
void Coordinates::set(const Coordinates& obj) {
	x = obj.x;
	y = obj.y;
}
void Coordinates::set(int x, int y) {
	this->x = x;
	this->y = y;
}
void Coordinates::set_x(int val) {
	x = val;
}
void Coordinates::set_y(int val) {
	y = val;
}
void Coordinates::move(int x, int y) {
	this->x += x;
	this->y += y;
}
bool Coordinates::operator ==(const Coordinates& obj) {
	if (x == obj.x && y == obj.y)
		return true;
	return false;
}