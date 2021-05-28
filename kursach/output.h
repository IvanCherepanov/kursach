#ifndef OUTPUT_H//для проверки не было ли значение ранее определено define'ом;предотвращает многократное использование
#define OUTPUT_H//создание макроса
#include "RootClass.h"
class Output
{
private:
	ifstream f;//объект для чтения
public:
	void outputFile();//метод для вывода содержимого файла(поле+данные)
};
#endif//если имя определено, то повторно не определяет