#pragma once
#include "Figure.h"
class Block_heap {
	Block* arr;
	int size;
public:
	Block_heap();
	~Block_heap();
	void add_figure(const Figure& obj);
	bool find(int, int);
	bool find(const Coordinates& obj);
	Block* get_arr();
	int get_size();
	void print();
	void erase();
	int check();
	void del_block(int val);
};