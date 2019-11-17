#include "Save.h"
Save::Save() {
	if (load())
		return;
	for (int i = 0; i < 5; i++) {
		arr[i] = 0;
		strcpy(names[i], "unsigned");
	}
}
bool Save::add(int val) {
	if (arr[0] > val)
		return false;
	char buf[12];
	system("cls");
	int i = 1;
	for (; i < 6; i++) {
		if (i == 5 || arr[i] > val)
			break;
	}
	for (int j = 0; j < i - 1; j++) {
		arr[j] = arr[j + 1];
		strcpy(names[j], names[j + 1]);
	}
	print(15, 15);
	Cursor(15, 20 - i);
	for (int i = 15; i < 59; i++)
		cout << ends;
	Cursor(15, 20 - i);
	cout << val << "\t";
	cin.getline(buf, 12);
	arr[i - 1] = val;
	strcpy(names[i - 1], buf);
	return true;
}
bool Save::check(int val) {
	return arr[0] < val;
}
bool Save::save() {
	fstream fs("save.bin", ios::out | ios::binary);
	if (fs.is_open()) {
		fs.write((char*)&arr, sizeof(arr));
		fs.write((char*)&names, sizeof(names));
		fs.close();
		return true;
	}
	return false;
}
bool Save::load() {
	fstream fs("save.bin", ios::in | ios::binary);
	if (fs.is_open()) {
		fs.read((char*)&arr, sizeof(arr));
		fs.read((char*)&names, sizeof(names));
		fs.close();
		return true;
	}
	return false;
}
int Save::get_score(int val) {
	return arr[val];
}
char* Save::get_name(int val) {
	return names[val];
}
void Save::print(int x, int y) {
	for (int i = 0; i < 5; i++) {
		Cursor(x, y + 4 - i);
		cout << arr[i] << "\t" << names[i];
	}
}