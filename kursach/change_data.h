#ifndef CHANGE_DATA
#define CHANGE_DATA
#include "RootClass.h"
#include "Input.h"
class Change_data_in_position : public RootClass {
private:
	// ��������� �� ������ ��� ������ � ����
	Input* input;
public:
	// ����������� ������
	Change_data_in_position();
	// �����-���������� �������
	void handlerDataFromApplication(string);
	// �����-������
	void signalToInput(string&);
};
#endif
