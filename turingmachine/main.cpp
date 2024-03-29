#include <iostream>
#include <string>
#include "Simulation.h"
#include "TmParser.h"

int main (int argc, char * const argv[]) 
{
	std::string const str_rules[] = {
		/*"1,a,x,r,2", "1,y,y,r,4",
		"2,a,a,r,2", "2,b,y,l,3", "2,y,y,r,2",
		"3,a,a,l,3", "3,x,x,r,1", "3,y,y,l,3",
		"4,y,y,r,4", "4, , ,r,0"*/

		/*"1,b,b,r,-1", "1,c,c,r,-1", "1, , ,r,-1", "1,a, ,r,2", 
		"2,c,c,r,-1", "2, , ,r,-1","2,a,a,r,2", "2,b,b,r,3", 
		"3,a,a,r,-1", "3, , ,r,-1", "3,b,b,r,3", "3,c,c,r,4", 
		"4,a,a,r,-1","4,b,b,r,-1", "4,c,c,r,4", "4, , ,l,5", 
		"5,a,a,l,5", "5,b,b,l,5", "5,c,c,l,5", "5, , ,r,6", 
		"6,a,a,r,6","6,b,#,r,7", "6,x,x,l,9", 
		"7,b,b,r,7", "7,x,x,r,7", "7, , ,r,-1", "7,c,x,l,8", 
		"8,b,b,l,8", "8,x,x,l,8","8,#,#,r,6", 
		"9,x,x,l,9", "9,#,#,l,9", "9,a,a,r,10", "9, , ,r,13", 
		"10,#,b,r,10", "10,x,x,l,11",
		"11,a,a,l,11", "11,b,b,l,11", "11, , ,r,12", "11,x,x,r,12", 
		"12,a,x,r,6", 
		"13,x,x,r,13", "13,#,#,r,13","13, , ,r,0"*/

		"0,a,a,r,1",
		"1,a,a,r,1", "1,b,b,r,2",
		"2,b,b,r,2", "2,c,c,r,3",
		"3,c,c,r,3", "3, , ,l,4",
		"4,a,a,l,4", "4,b,b,l,4", "4,c,c,l,4", "4, , ,r,5",
		"5,a,x,r,6",
		"6,a,a,r,6", "6,b,y,r,7", "6,y,y,r,6", "6,z,z,l,9",
		"7,b,b,r,7", "7,c,z,l,8", "7,z,z,r,7",
		"8,b,b,l,8", "8,y,y,r,6", "8,z,z,l,8",
		"9,a,a,l,9", "9,x,x,r,10", "9,y,b,l,9", "9,z,z,l,9",
		"10,a,x,r,6", "10,b,b,r,11", "10,y,y,r,11",
		"11,b,b,r,11", "11,y,y,r,11", "11,z,z,r,11", "11, , ,r,accept"
	};
	std::vector<std::string> rules(std::begin(str_rules), std::end(str_rules));
	Simulation* mainSim = new Simulation(rules);
	
	std::string input;
	std::cout << "Input a string(q to quit)." << std::endl;
	while (true)
	{
		std::cin >> input;
		if (input == "q" || input == "Q") break;
		mainSim->setTape(input);
		mainSim->wholeSimulation();
		//vector<char> v = mainSim->getActiveConfig()->getTape()->getContent();
		//std::string str2(v.begin(),v.end());
		//std::cout << str2 << std::endl;
	}
}
