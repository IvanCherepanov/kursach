
#include "change_data.h"

Change_data_in_position::Change_data_in_position() {
	this->input = new Input;
	setConnection(SIGNAL_D(Change_data_in_position::signalToInput), this->input, HANDLER_D(Input::handlerCoord));
}

void Change_data_in_position::handlerDataFromApplication(string info) {
	vector<string> infoVector = getFormatData(info);
	if (infoVector[0] == "NULL") return;
	sendSignal(SIGNAL_D(Change_data_in_position::signalToInput), info);
}
void Change_data_in_position::signalToInput(string& info) {
	vector<string> toInputVector = getFormatData(info);
	string coord1 = toInputVector[0];
	string coord2 = toInputVector[1];

	int x = stoi(coord1);
	int y = stoi(coord2);
	string symbol = toInputVector[2];

	if (x < 1 || y < 1 || x>10 || y>10) {
		info = "Coordinate is wrong ( " + coord1 + ", " + coord2 + " )";
	}
	else if (!(symbol[0] >= 'A' && symbol[0] <= 'Z' || symbol[0] >= 'a' && symbol[0] <= 'z')) {
		info = "Not a letter of the Latin alphabet: " + symbol;
	}
}
