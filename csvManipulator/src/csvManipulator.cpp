#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <iterator>
#include <algorithm>


#include <iostream>
#include "csvManipulator.h"
using namespace std;

void csvManipulator::readData(ifstream& csv) {

	//Getting data from input file and storing them in 2D Vectors
	if (csv) {
		string line;
		while (getline(csv, line)) {
			stringstream comma_sep(line);
			string cell;
			fields.push_back(vector<int>());

			while (getline(comma_sep, cell, ',')) {
				fields.back().push_back(std::stoi(cell));
			}
		}
	}
}

void csvManipulator::writeData(ofstream& write) {
	for (auto row : fields) {
		findZero(row);
		for (auto field : row) {
			cout << field << ' ';
			write << field << ",";
		}
			write << '\n';
			cout << '\n';
	}
}

void csvManipulator::findZero(vector<int>& row) {

	for (vector<int>::iterator i = row.begin(); i != row.end(); i++) {
		if (*i == 0) {

			int prev = 0;
			int next = 0;
			int pos = distance(row.begin(), i);

			if (i == row.begin()) {
				prev = pos + 2;
				next = pos + 1;
			}
			if (i == row.end()) {
				prev = pos - 2;
				next = pos - 1;
			}
			if (i != row.begin() && i != row.end() - 1) {
				prev = pos - 1;
				next = pos + 1;
			}


			int A = row[prev];
			int B = row[next];

			int Average = (A + B) / 2;
			*i = Average;


			std::cout << "Found 0 at: " << i - row.begin() << endl;

		}

	}
}
