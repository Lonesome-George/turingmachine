#ifndef SIMULATION_H
#define	SIMULATION_H

#define MAX_ITERATIONS 5000

#include <vector>
#include <map>
#include <string>
#include "Tape.h"
#include "Transition.h"

class Simulation {
public:
	Simulation::Simulation(vector<std::string>);
    Simulation(const Simulation& orig);
    virtual ~Simulation();
	void setTape(std::string);
    void oneStep();
    void wholeSimulation();
    void addTransition(const char, const char, const int, const std::string, const std::string);

private:
	Tape* tape;
	std::string curState;
    multimap<std::string,Transition*> transitions;
};

#endif	/* SIMULATION_H */

