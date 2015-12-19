#include "Transition.h"
#include <vector>
#include <string>

using namespace std;


Transition::Transition(char rd, char wt, char mv, std::string src, std::string dest){
	read = rd;
	write = wt;
	move = mv;
	sourceState = src;
	nextState = dest;
}

char Transition::getRead() const {
    return read;
}

char Transition::getWrite() const {
    return write;
}

char Transition::getMove() const {
    return move;
}

const std::string Transition::getNextState() const {
    return nextState;
}
