#pragma once
#include <iostream>
#include <windows.h>
#include "Coordinates.h"
#include "Win.h"
class Block : public Coordinates {
	int color;
public:
	Block();
	Block(const Coordinates& obj, int);
	Block(const Block& obj);
	void set(const Coordinates& obj, int);
	void set(const Coordinates& obj);
	void set(int, int);
	int get_color();
	Coordinates get_coord();
	void set_color(int);
	void move(int, int);
	bool operator ==(const Block& obj);
	Block& operator =(const Block& obj);
	void print();
	void erase();
};
