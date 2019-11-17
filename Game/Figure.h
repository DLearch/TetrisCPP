#pragma once
#include "Block.h"
class Figure {
	Block arr[4];
	int type, rt;
public:
	Figure(int, int);
	void rotate();
	Figure(const Figure& obj);
	void print();
	void erase();
	int get_type();
	Block get_elem(int) const;
	void move(int, int);
	Figure& operator =(const Figure& obj);
};