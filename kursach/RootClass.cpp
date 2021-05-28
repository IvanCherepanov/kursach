#include "RootClass.h"
//void RootClass::setConnection(int coord1,int coord2,char symp, TYPE_SIGNAL signal, RootClass*ob, TYPE_HANDLER handler) {
//	(this->connects).push_back(make_tuple(coord1, coord2, symp, signal, ob, handler));
//}
Connects::Connects(TYPE_SIGNAL signal, RootClass* recepient, TYPE_HANDLER
	handler) {
	this->signal = signal;
	this->recepient = recepient;
	this->handler = handler;
}
void RootClass::setConnection(TYPE_SIGNAL signal, RootClass* recipientS, TYPE_HANDLER
	handler) {
	Connects* connects = new Connects(signal, recipientS, handler);
	this->connects.push_back(connects);
}
void RootClass::sendSignal(TYPE_SIGNAL signal, string&command ) {
	TYPE_HANDLER handler;
	RootClass* recepient;
	(this->*signal) (command);
	for (int i = 0; i < this->connects.size(); i++)
	{
		if (connects[i]->signal == signal)
		{
			handler = connects[i]->handler;
			recepient = connects[i]->recepient;
			(recepient->*handler)(command);
		}

	}


}
vector<string> RootClass::getFormatData(string command) {
	vector<string> readyData;

	string tmp = command;
	//char delimiter = ' ';

	int pos = tmp.find(' ');
	readyData.push_back(tmp.substr(0, pos));
	tmp.erase(0, pos + 1);

	pos = tmp.find(' ');
	readyData.push_back(tmp.substr(0, pos));
	tmp.erase(0, pos + 1);

	if (stoi(readyData[0]) == 0 && stoi(readyData[1]) == 0) {
		vector<string> errorV = { "NULL" };
		return errorV;
	}
	readyData.push_back(tmp);
	return readyData;
}

