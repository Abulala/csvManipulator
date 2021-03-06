#include "csvManipulator.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc,char **argv)
{
	if (argc != 3){
		std::cerr << "Usage: " << argv[0] << "your.csv output.csv" << endl;
		return 1;}
//Initializing input and output files	
	ifstream in;
	in.open(argv[1]);
	ofstream outp;
	outp.open(argv[2]);
	
	if (!in.is_open()){
		cerr << "ERROR: Bad input file" << '\n';
		return 1;}
//Initializing class	
	csvManipulator csv;

//Class interface that deals with setting data
	csv.readData(in);
//Clas interface that deals with getting data
	csv.writeData(outp);

//Successfully manipulated
	cout << endl << "Output CSV file succesfully generated!";

	getchar();
	return 0;
}



