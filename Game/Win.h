#pragma once
#include <windows.h>
enum {
	clBlack, clNavy, clGreen, clTeal, clBrown,
	clPurple, clOlive, clGray, clSilver, clBlue,
	clLime, clCyan, clRed, clMagneta, clYellow,
	clWhite
};
void SetConsoleWinSizePosition(int width, int heigth);
void ColorTB(int Tex, int Bg);
void Cursor(short x_position, short y_position);