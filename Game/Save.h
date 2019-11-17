#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <fstream>
#include "Win.h"
using namespace std;
class Save {
	int arr[5];
	char names[5][12];
public:
	Save();
	bool add(int);
	bool check(int);
	bool save();
	bool load();
	int get_score(int);
	char* get_name(int);
	void print(int, int);
};
