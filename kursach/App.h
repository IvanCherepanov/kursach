#ifndef APP_H
#define APP_H
#include "Change_data.h"
#include "Output.h"
#include "Input.h"
class App : public RootClass {
private:
	Change_data_in_position* change_data_in_position;//������ ��� ��������� ������� � ����� �������� ����������
	Output* output;//������ ������ ������ ���������� �� ����� �� �������.
	Input* input;//��� ������ ������� � ����� � ������������� �������. ������ ����� ������ � ������������� ������� ��� ������� � ����� ����� ��������� �� ������.
	bool flagInput;//����������-���� ��� ����������� ����� ����-�������
public:
	App();//�����������
	int execute();//������� �������, ����������� ��������
	void signalToPosition(string& str);//����� ������� ��� ��������� �������

};
#endif