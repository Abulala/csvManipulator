#ifndef CVSMANIPULATOR_H
#define CVSMANIPULATOR_H



#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <iterator>
#include <algorithm>

class csvManipulator {
	std::vector<std::vector<int> > fields;
public:
	void readData(std::ifstream& csv);
	void writeData(std::ofstream& write);
	void findZero(std::vector<int>& row);
};

#endif 
