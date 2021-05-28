#ifndef CHANGE_DATA
#define CHANGE_DATA
#include "RootClass.h"
#include "Input.h"
class Change_data_in_position : public RootClass {
private:
	// Указатель на объект для записи в файл
	Input* input;
public:
	// Конструктор класса
	Change_data_in_position();
	// Метод-обработчик сигнала
	void handlerDataFromApplication(string);
	// Метод-сигнал
	void signalToInput(string&);
};
#endif
