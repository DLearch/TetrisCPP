#include "Block.h"
Block::Block() : color(0) {}
Block::Block(const Coordinates& obj, int val) : Coordinates(obj), color(val) {}
Block::Block(const Block& obj) : Coordinates(obj), color(obj.color) {}
void Block::set(const Coordinates& obj, int val) {
	Coordinates::set(obj);
	color = val;
}
void Block::set(const Coordinates& obj) {
	Coordinates::set(obj);
}
void Block::set(int x, int y) {
	this->x = x;
	this->y = y;
}
int Block::get_color() {
	return color;
}
Coordinates Block::get_coord() {
	return Coordinates(x, y);
}
void Block::set_color(int val) {
	color = val;
}
void Block::move(int x, int y) {
	Coordinates::move(x, y);
}
bool Block::operator ==(const Block& obj) {
	if (x == obj.x && y == obj.y)
		return true;
	return false;
}
Block& Block::operator =(const Block& obj) {
	Coordinates::set(obj);
	color = obj.color;
	return *this;
}
void Block::print() {
	ColorTB(clBlack, color);
	for (int i = 0; i < 2; i++) {
		Cursor(x, y + i);
		for (int j = 0; j < 4; j++) {
			if (x + i >= 0 && x + i <= 59 && y + i >= 0 && y + i <= 39)
				std::cout << ' ';
		}
	}
}
void Block::erase() {
	ColorTB(clBlack, clGray);
	for (int i = 0; i < 2; i++) {
		Cursor(x, y + i);
		for (int j = 0; j < 4; j++) {
			if (x + i >= 0 && x + i <= 59 && y + i >= 0 && y + i <= 39)
				std::cout << ' ';
		}
	}
}