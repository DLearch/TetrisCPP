#pragma once
class Coordinates {
protected:
	int x, y;
public:
	Coordinates();
	Coordinates(int, int);
	Coordinates(const Coordinates& obj);
	Coordinates& operator =(const Coordinates& obj);
	int get_x()const;
	int get_y()const;
	void set(const Coordinates& obj);
	void set(int, int);
	void set_x(int);
	void set_y(int);
	void move(int, int);
	bool operator ==(const Coordinates& obj);
};