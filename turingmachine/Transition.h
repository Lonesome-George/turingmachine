#ifndef DEF_TRANSITION
#define DEF_TRANSITION

#include <vector>
#include <string>

using namespace std;

class Transition{
	
public:
    Transition(char, char, char, const std::string, const std::string);
    char getRead() const;
    char getWrite() const;
    char getMove() const;
    const std::string getNextState() const;
	
private:
	char read;
	char write;
	char move;
	std::string sourceState;
	std::string nextState;
};




#endif
