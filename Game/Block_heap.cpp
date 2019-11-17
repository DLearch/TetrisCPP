#include "Block_heap.h"
Block_heap::Block_heap() : size(0), arr(nullptr) {}
Block_heap::~Block_heap() {
	if (arr != nullptr)
		delete[] arr;
}
void Block_heap::add_figure(const Figure& obj) {
	if (size == 0)
		arr = new Block[4];
	else {
		Block* tmp = new Block[size + 4];
		for (int i = 0; i < size; i++)
			tmp[i] = arr[i];
		delete[] arr;
		arr = tmp;
	}
	for (int i = 0; i < 4; i++)
		arr[size + i] = obj.get_elem(i);
	size += 4;
}
bool Block_heap::find(int x, int y) {
	return find(Coordinates(x, y));
}
bool Block_heap::find(const Coordinates& obj) {
	for (int i = 0; i < size; i++) {
		if (arr[i].get_coord() == obj)
			return true;
	}
	return false;
}
Block* Block_heap::get_arr() {
	return arr;
}
int Block_heap::get_size() {
	return size;
}
void Block_heap::print() {
	for (int i = 0; i < size; i++)
		arr[i].print();
}
void Block_heap::erase() {
	for (int i = 0; i < size; i++)
		arr[i].erase();
}
int Block_heap::check() {
	int lines = 0;
	for (int k = 0, row = 38; row; row -= 2, k = 0) {
		for (int i = 0; i < size; i++) {
			if (arr[i].get_y() == row)
				k++;
		}
		if (k == 0)
			return lines;
		if (k == 10) {
			erase();
			for (int i = 0; i < size; i++) {
				while (true) {
					if (arr[i].get_y() != row)
						break;
					del_block(i);
					continue;
				}
				if (arr[i].get_y() < row)
					arr[i].move(0, 2);
			}
			row += 2;
			lines++;
			print();
		}
	}
	return lines;
}
void Block_heap::del_block(int val) {
	if (val < 0 || val >= size)
		return;
	if (size == 1) {
		size--;
		delete[] arr;
		arr = nullptr;
		return;
	}
	size--;
	Block* tmp = new Block[size];
	for (int i = 0; i < size; i++)
		tmp[i] = arr[i < val ? i : i + 1];
	delete[] arr;
	arr = tmp;
}