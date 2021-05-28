#ifndef APP_H
#define APP_H
#include "Change_data.h"
#include "Output.h"
#include "Input.h"
class App : public RootClass {
private:
	Change_data_in_position* change_data_in_position;//объект для установки позиции в файле согласно координате
	Output* output;//объект дляДля вывода результата из файла на консоль.
	Input* input;//Для записи символа в файле в установленную позицию. Объект пишет символ в установленной позиции или выводит в конце файла сообщение об ошибке.
	bool flagInput;//переменная-флаг для определения ввода стоп-символа
public:
	App();//конструктор
	int execute();//главная функция, реализующая алгоритм
	void signalToPosition(string& str);//метод сигнала для обработки позиции

};
#endif