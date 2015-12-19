#include <iostream>
#include "Simulation.h"

void split(std::string const str, std::string& delim, std::vector< std::string >* ret)
{
	int prev = 0;
	while(true)
	{
		int next = str.find(delim, prev);
		if (next != string::npos) {
			ret->push_back(str.substr(prev, next-prev));
			prev = next + 1;
		}
		else {
			ret->push_back(str.substr(prev));
			break;
		}
	}
}

void parseTuring(vector<std::string> rules, Simulation* sim) {
	string delim = ",";
	for (string st : rules) {
		vector<std::string> *temp_str = new vector<std::string>;
		split(st, delim, temp_str);
		string sourceState = temp_str->at(0);
		char read = temp_str->at(1)[0];
		char write = temp_str->at(2)[0];
		int move = temp_str->at(3)[0];
		string destState = temp_str->at(4);
		sim->addTransition(read, write, move, sourceState, destState);
		delete temp_str;
	}
}
