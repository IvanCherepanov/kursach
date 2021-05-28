#include "Input.h"

void Input::createNewFile()
{
	ofstream f("field.txt");
	//f.open("field.txt");
	for (int i = 1; i <= 10; i++) {
		f << 8888888888;
		if (i != 10) f << endl;
	}
	f.close();
}
void Input::handlerCoord(string command) {
	if (command.find("Coordinate is wrong ( ", 0) != string::npos || command.find("Not a letter of the Latin alphabet: ", 0) != string::npos) {
		this->inputError(command);
	}
	else {
		vector<string> commandV = getFormatData(command);
		int x = stoi(commandV[0]);
		int y = stoi(commandV[1]);
		char c = commandV[2][0];
		this->inputNewSymbol(x, y,c);//commandV[2][0]
	}
}
void Input::inputError(string error) {
	this->f.open("field.txt", ofstream::app);

	f << endl << error;
	this->f.close();
}
void Input::inputNewSymbol(int x, int y, char symbol) {
	f.open("field.txt");
	vector<string> data;
	string str;
	while (getline(f, str)) {
		data.push_back(str);
	}
	f.close();

	f.open("field.txt");

	if (x - 1 == 0) {
		data[0][y - 1] = symbol;
	}
	f << data[0];
	for (int i = 1; i < data.size(); i++) {
		if (i == x - 1) {
			data[i][y - 1] = symbol;
		}
		f << endl << data[i];
	}
	f.close();
}
