#ifndef INPUT_H
#define INPUT_H

#include "RootClass.h"

class Input:public RootClass
{
private:
	fstream f;//����� ��� ������ �����(����� ���������)
public:
	void createNewFile();//����� ��� �������� � ���������� ����� �������������
	// �����-����������
	void handlerCoord(string);
	// ����� ������ ������ � ����
	void inputError(string);
	// ����� ������ ������� � �������� �������
	void inputNewSymbol(int, int, char);
};

#endif
