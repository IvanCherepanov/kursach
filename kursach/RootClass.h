#ifndef ROOT_CLASS_H
#define ROOT_CLASS_H
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
using namespace std;
class RootClass;
//����� �� �������� ��������, �.� ������� ����� ��������� �����

typedef void (RootClass::* TYPE_HANDLER) (string);
// ���������������� ������� � ���� TYPE_SIGNAL � TYPE_HANLDER
typedef void (RootClass::* TYPE_SIGNAL) (string&);
// ��������� �� ������� �����������

#define SIGNAL_D(signal_f)(TYPE_SIGNAL)(& signal_f)
//  #define SIGNAL_D(signal_f)(TYPE_SIGNAL)(& signal_f);
#define HANDLER_D(handler_f)(TYPE_HANDLER)(& handler_f)
  //#define HANDLER_D(handler_f)(TYPE_HANDLER)(& handler_f);
//#define HANDLER_D(handler_f)(TYPE_HANDLER)(& handler_f)
//���������������� � ���������� - �������� ����� � ���� ���������

//���������������� � ���������� - �������� ����� � ���� ���������

struct Connects {
public:
	// ��������� �� �����-������
	TYPE_SIGNAL signal;
	// �������� �� ������� ������
	RootClass* recepient;
	// ��������� �� �����-����������
	TYPE_HANDLER handler;
	// ������������������� ����������� ������
	Connects(TYPE_SIGNAL, RootClass*, TYPE_HANDLER);
};

class RootClass
{
private:
	vector<Connects*> connects;
public:
	//list<tuple< TYPE_SIGNAL, RootClass*, TYPE_HANDLER>>connects;
	
	//list<tuple<int, int, char, TYPE_SIGNAL, RootClass*, TYPE_HANDLER>>connects;
	//void setConnection(int coord1, int coord2, char s, TYPE_SIGNAL signal, RootClass* ob, TYPE_HANDLER handler);//��� �����
	void setConnection(TYPE_SIGNAL, RootClass*, TYPE_HANDLER);//��� �����
	//void deleteConnection(string sender, string recipient);
	//void sendSignal(RootClass* recipient, string& command, TYPE_HANDLER handler);// RootClass* sender
	void sendSignal(TYPE_SIGNAL signal, string& command);// RootClass* sender
	vector<string> getFormatData(string);
};
#endif

