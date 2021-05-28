#include "Output.h"

void Output::outputFile()
{
	f.open("field.txt");
	string str;
	getline(f, str);
	cout << str;
	while (true) {
		getline(f, str);
		if (!f) break;
		cout << endl<<str;
	}
	/*
	getline(f, str);
	cout << str;
	while (getline(f,str)) {
		cout << endl<<str;
	}
	*/
	/*while (true)
	{
		f >>str;
		if (!f)
			break;
		cout << str;
	}*/
	f.close();
}
