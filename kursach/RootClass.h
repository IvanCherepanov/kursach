#ifndef ROOT_CLASS_H
#define ROOT_CLASS_H
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
using namespace std;
class RootClass;
//чтобы не ругались тайпдефы, т.к главный класс описываем позже

typedef void (RootClass::* TYPE_HANDLER) (string);
// ћекроопределение методов к типу TYPE_SIGNAL и TYPE_HANLDER
typedef void (RootClass::* TYPE_SIGNAL) (string&);
// ”казатель на функцию обработчика

#define SIGNAL_D(signal_f)(TYPE_SIGNAL)(& signal_f)
//  #define SIGNAL_D(signal_f)(TYPE_SIGNAL)(& signal_f);
#define HANDLER_D(handler_f)(TYPE_HANDLER)(& handler_f)
  //#define HANDLER_D(handler_f)(TYPE_HANDLER)(& handler_f);
//#define HANDLER_D(handler_f)(TYPE_HANDLER)(& handler_f)
//макроопределение с параметром - приводит метод к типу указател€

//макроопределение с параметром - приводит метод к типу указател€

struct Connects {
public:
	// ”казатель на метод-сигнал
	TYPE_SIGNAL signal;
	// ”казатеь на целевой объект
	RootClass* recepient;
	// ”казатель на метод-обработчик
	TYPE_HANDLER handler;
	// ѕараметризированный конструктор класса
	Connects(TYPE_SIGNAL, RootClass*, TYPE_HANDLER);
};

class RootClass
{
private:
	vector<Connects*> connects;
public:
	//list<tuple< TYPE_SIGNAL, RootClass*, TYPE_HANDLER>>connects;
	
	//list<tuple<int, int, char, TYPE_SIGNAL, RootClass*, TYPE_HANDLER>>connects;
	//void setConnection(int coord1, int coord2, char s, TYPE_SIGNAL signal, RootClass* ob, TYPE_HANDLER handler);//дл€ св€зи
	void setConnection(TYPE_SIGNAL, RootClass*, TYPE_HANDLER);//дл€ св€зи
	//void deleteConnection(string sender, string recipient);
	//void sendSignal(RootClass* recipient, string& command, TYPE_HANDLER handler);// RootClass* sender
	void sendSignal(TYPE_SIGNAL signal, string& command);// RootClass* sender
	vector<string> getFormatData(string);
};
#endif

