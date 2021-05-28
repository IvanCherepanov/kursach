#ifndef INPUT_H
#define INPUT_H

#include "RootClass.h"

class Input:public RootClass
{
private:
	fstream f;//нужен для записи файла(будем создавать)
public:
	void createNewFile();//метод для создания и заполнения файла автоматически
	// Метод-обработчик
	void handlerCoord(string);
	// Метод записи ошибки в файл
	void inputError(string);
	// Метод записи символа в заданную позицию
	void inputNewSymbol(int, int, char);
};

#endif
