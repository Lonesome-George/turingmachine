#include <iostream>
#include "Simulation.h"
#include "TmParser.h"
#include <time.h>
#include <stdlib.h>
#include <assert.h>

Simulation::Simulation(vector<std::string> rules) {
	parseTuring(rules, this);
}

Simulation::Simulation(const Simulation& orig) {
}

Simulation::~Simulation() {
    for (auto t : transitions) {
        delete t.second;
    }
	delete tape;
}

void Simulation::setTape(std::string stringTape) {
	if (tape != NULL) delete tape;
	std::vector<char> vectorCopy(stringTape.size() + 1);
	std::copy(stringTape.begin(), stringTape.end(), vectorCopy.begin());
	vectorCopy.pop_back(); // Erase the ending \O character
	tape = new Tape(vectorCopy);
}

void Simulation::oneStep() {
    //Search for possible transitions by source state
    vector<Transition*> filteredTransitions;
	//std::cout << curState << " ==> ";
    auto ret = transitions.equal_range(curState);
    for (auto it=ret.first;it!=ret.second;++it) {
        filteredTransitions.push_back((*it).second);
    }
    if (filteredTransitions.empty()) {
		curState = "reject";
		return;
    }
    
    //Search for possible transitions by read character
    vector<Transition*> possibleTransitions;
	char readValue = tape->getChar();
    for (Transition* tr : filteredTransitions ) {
        if (tr->getRead() == readValue) {
            possibleTransitions.push_back(tr);
        }
    }
    if (possibleTransitions.empty()) {
		curState = "reject";
		return;
    }
    
    // transition
	assert(possibleTransitions.size() == 1); // cannot copy with multi transitions
	Transition* select = possibleTransitions[0];
	char wt = select->getWrite();
	char mv = select->getMove();
	std::string nextState = select->getNextState();
	tape->setChar(wt);
	tape->move(mv);
	curState = nextState;

	//std::cout << nextState << std::endl;
}

/*
 * Whole Simulation
 */
void Simulation::wholeSimulation() {
	curState = "0"; // set initial state
    int steps = 0;
    while(curState != "accept" && curState != "reject") {
        oneStep();
        steps++;
        if (steps > MAX_ITERATIONS) {
            std::cout << "Moved too many steps !" << std::endl;
            exit(1);
        }
    }
	std::cout << curState << std::endl;
}

/*
 * Add a transition
 * - vector<char> chars to read
 * - vector<char> chars to write
 * - vector<int>  directions to move
 * - State source state
 * - State dest state
 */
void Simulation::addTransition(const char read, const char write, const int move, const std::string sourceState, const std::string destState) {
    Transition* tr = new Transition(read, write, move, sourceState, destState);
    transitions.insert(pair<std::string,Transition*>(sourceState, tr));
}
