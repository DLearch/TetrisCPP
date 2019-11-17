#include "Figure.h"
Figure::Figure(int x, int y) {
	arr[0].set(x, y);
	type = rand() % 7;
	switch (type) {
	case 0: // Квадрат
		rt = 0;
		for (int i = 0; i < 4; i++)
			arr[i].set_color(clPurple);
		break;
	case 1: // Палка
		rt = rand() % 2;
		for (int i = 0; i < 4; i++)
			arr[i].set_color(clBlue);
		break;
	case 2: // закорючка верхом влево
		rt = rand() % 2;
		for (int i = 0; i < 4; i++)
			arr[i].set_color(clRed);
		break;
	case 3: // закорючка верхом вправо
		rt = rand() % 2;
		for (int i = 0; i < 4; i++)
			arr[i].set_color(clGreen);
		break;
	case 4: // тройка
		rt = rand() % 4;
		for (int i = 0; i < 4; i++)
			arr[i].set_color(clYellow);
		break;
	case 5: // угол влево
		rt = rand() % 4;
		for (int i = 0; i < 4; i++)
			arr[i].set_color(clOlive);
		break;
	case 6: // угол вправо
		rt = rand() % 4;
		for (int i = 0; i < 4; i++)
			arr[i].set_color(clCyan);
		break;
	}
	rotate();
}
void Figure::rotate() {
	for (int i = 1; i < 4; i++)
		arr[i] = arr[0];
	switch (type) {
	case 0:
		arr[1].move(0, -2);
		arr[2].move(4, -2);
		arr[3].move(4, 0);
		break;
	case 1:
		if (rt == 0) {
			arr[1].move(0, -2);
			arr[2].move(0, -4);
			arr[3].move(0, 2);
		}
		else {
			arr[1].move(-4, 0);
			arr[2].move(4, 0);
			arr[3].move(8, 0);
		}
		rt = rt == 0 ? 1 : 0;
		break;
	case 2:
		if (rt == 0) {
			arr[1].move(0, -2);
			arr[2].move(4, 0);
			arr[3].move(4, 2);
		}
		else {
			arr[1].move(4, 0);
			arr[2].move(0, 2);
			arr[3].move(-4, 2);
		}
		rt = rt == 0 ? 1 : 0;
		break;
	case 3:
		if (rt == 0) {
			arr[1].move(0, -2);
			arr[2].move(-4, 0);
			arr[3].move(-4, 2);
		}
		else {
			arr[1].move(-4, 0);
			arr[2].move(0, 2);
			arr[3].move(4, 2);
		}
		rt = rt == 0 ? 1 : 0;
		break;
	case 4:
		if (rt == 0) {
			arr[1].move(0, -2);
			arr[2].move(-4, 0);
			arr[3].move(4, 0);
		}
		if (rt == 1) {
			arr[1].move(4, 0);
			arr[2].move(0, -2);
			arr[3].move(0, 2);
		}
		if (rt == 2) {
			arr[1].move(0, 2);
			arr[2].move(4, 0);
			arr[3].move(-4, 0);
		}
		if (rt == 3) {
			arr[1].move(-4, 0);
			arr[2].move(0, 2);
			arr[3].move(0, -2);
		}
		rt = rt == 3 ? 0 : rt + 1;
		break;
	case 5:
		if (rt == 0) {
			arr[1].move(-4, 0);
			arr[2].move(0, -2);
			arr[3].move(0, -4);
		}
		if (rt == 1) {
			arr[1].move(-4, 0);
			arr[2].move(-4, -2);
			arr[3].move(4, 0);
		}
		if (rt == 2) {
			arr[1].move(0, -2);
			arr[2].move(0, 2);
			arr[3].move(4, -2);
		}
		if (rt == 3) {
			arr[1].move(-4, 0);
			arr[2].move(4, 0);
			arr[3].move(4, 2);
		}
		rt = rt == 3 ? 0 : rt + 1;
		break;
	case 6:
		if (rt == 0) {
			arr[1].move(4, 0);
			arr[2].move(0, -2);
			arr[3].move(0, -4);
		}
		if (rt == 1) {
			arr[1].move(4, 0);
			arr[2].move(-4, 0);
			arr[3].move(-4, 2);
		}
		if (rt == 2) {
			arr[1].move(0, 2);
			arr[2].move(0, -2);
			arr[3].move(-4, -2);
		}
		if (rt == 3) {
			arr[1].move(-4, 0);
			arr[2].move(4, 0);
			arr[3].move(4, -2);
		}
		rt = rt == 3 ? 0 : rt + 1;
		break;
	}
}
Figure::Figure(const Figure& obj) {
	for (int i = 0; i < 4; i++)
		arr[i] = obj.arr[i];
	type = obj.type;
	rt = obj.rt;
}
void Figure::print() {
	for (int i = 0; i < 4; i++)
		arr[i].print();
}
void Figure::erase() {
	for (int i = 0; i < 4; i++)
		arr[i].erase();
}
int Figure::get_type() {
	return type;
}
Block Figure::get_elem(int val) const {
	return arr[val];
}
void Figure::move(int x, int y) {
	erase();
	for (int i = 0; i < 4; i++)
		arr[i].move(x, y);
	print();
}
Figure& Figure::operator =(const Figure& obj) {
	for (int i = 0; i < 4; i++)
		arr[i] = obj.arr[i];
	type = obj.type;
	rt = obj.rt;
	return *this;
}