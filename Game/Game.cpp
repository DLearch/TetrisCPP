#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <ctime>
#include <fstream>
#include "Win.h"
#include "Coordinates.h"
#include "Block.h"
#include "Figure.h"
#include "Block_heap.h"
#include "Save.h"
using namespace std;
enum { K_UP = 72, K_LEFT = 75, K_RIGHT = 77, K_DOWN = 80, K_ENTER = 13, K_ESC = 27, K_SPACE = 32 };
int game(int x, int y) {
	ColorTB(clBlack, clGray);
	system("cls");
	Save sav;
	sav.load();
	sav.print(43, 33);
	ColorTB(clBlack, clBlack);
	for (int i = 0; i < y + 1; i++) {
		Cursor(40, i);
		cout << ends;
	}
	ColorTB(clBlack, clGray);
	Cursor(45, 5);
	cout << "Очки - 0" << endl;
	int speed = 200, score = 0, key, boost, move;
	bool tmp;
	Figure figure(16, -4), fg_tmp(figure), fg_next(48, 20);
	fg_next.rotate();
	fg_next.print();
	Block_heap heap;
	while (1) {
		move = 0;
		key = heap.check();
		if (key > 0) {
			score += key + (key > 1 ? key / 2 : 0);
			ColorTB(clBlack, clGray);
			Cursor(52, 5);
			cout << score;
		}
		for (int i = 0; i < 4; i++) {
			if (heap.find(figure.get_elem(i).get_x(), figure.get_elem(i).get_y())) {
				ColorTB(clBlack, clGray);
				Cursor(0, 39);
				return score;
			}
		}
		boost = 1;
		if (_kbhit()) {
			key = _getch();
			if (key == 0xe0) {
				key = _getch();
				if (key == K_LEFT) {
					tmp = true;
					for (int i = 0; i < 4; i++) {
						if (heap.find(figure.get_elem(i).get_x() - 4, figure.get_elem(i).get_y()) || figure.get_elem(i).get_x() - 4 < 0)
							tmp = false;
					}
					if (tmp)
						figure.move(-4, 0);
				}
				if (key == K_RIGHT) {
					tmp = true;
					for (int i = 0; i < 4; i++) {
						if (heap.find(figure.get_elem(i).get_x() + 4, figure.get_elem(i).get_y()) || figure.get_elem(i).get_x() + 4 > 39)
							tmp = false;
					}
					if (tmp)
						figure.move(4, 0);
				}
				if (key == K_DOWN)
					boost = 8;
				if (key == K_UP) {
					tmp = true;
					fg_tmp = figure;
					fg_tmp.rotate();
					for (int i = 0; i < 4; i++) {
						if (heap.find(fg_tmp.get_elem(i).get_x(), fg_tmp.get_elem(i).get_y()) || fg_tmp.get_elem(i).get_x() > 39 || fg_tmp.get_elem(i).get_x() < 0 || fg_tmp.get_elem(i).get_y() > 39)
							tmp = false;
					}
					if (tmp) {
						figure.erase();
						figure.rotate();
						figure.print();
					}
				}
			}
			if (key == K_ESC) {
				ColorTB(clBlack, clGray);
				Cursor(0, 39);
				return score;
			}
		}
		for (int i = 0; i < 4; i++) {
			if (heap.find(figure.get_elem(i).get_x(), figure.get_elem(i).get_y() + 2) || figure.get_elem(i).get_y() + 2 > 38) {
				heap.add_figure(figure);
				fg_next.erase();
				fg_next.move(-32, -26);
				figure = fg_next;
				fg_next = Figure(48, 20);
				fg_next.print();
				if (speed > 80)
					speed -= 5;
				break;
			}
		}
		for (int i = 0; i < 2; i++) {
			figure.move(0, 1);
			Sleep(speed / boost);
		}
	}
}
void main() {
	srand((unsigned)time(NULL));
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	const int x = 61, y = 39;
	SetConsoleWinSizePosition(x, y);
	int score;
	Save sav;
	sav.load();
	while (true) {
		score = 0;
		ColorTB(clBlack, clGray);
		system("cls");
		sav.print(15, 15);
		Cursor(15, 30);
		cout << "Нажмите SPACE для начала игры";
		Cursor(15, 32);
		cout << "Нажмите ESC для выхода из игры";
		int key;
		while (key = _getch()) {
			if (key == K_ESC) {
				system("cls");
				Cursor(0, y);
				return;
			}
			if (key == K_SPACE)
				break;
			Sleep(10);
		}
		if ((score = game(x, y)) && sav.check(score)) {
			sav.add(score);
			sav.save();
		}
	}
}