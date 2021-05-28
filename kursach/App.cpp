#include "App.h"

App::App() {
	this->change_data_in_position = new Change_data_in_position;
	this->output = new Output;
	this->input = new Input;
	this->flagInput = false;
	setConnection(SIGNAL_D(App::signalToPosition), 
		this->change_data_in_position,
		HANDLER_D(Change_data_in_position::handlerDataFromApplication));
}
int App::execute()
{
	this->input->createNewFile();

	string help;
	while (true) {
		if (this->flagInput) {
			break;
		}
		sendSignal(SIGNAL_D(App::signalToPosition), help);
	}

	this->output->outputFile();

	return 0;
}
void App::signalToPosition(string& str) {
	string x, y;
	char symbol = ' ';
	cin >> x >> y;
	if (x == "0" && y == "0") {
		this->flagInput = true;
	}
	else {
		cin >> symbol;
	}
	str = x + ' ' + y + ' ' + symbol;
}
