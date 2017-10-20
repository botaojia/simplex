/*
 Copyright (C) 2010 Botao Jia

 This file is an testing of the implementation of the nonlinear-lease-square fitting 
 using downhill simplex optimization algorithm using C++.

 You can redistribute it and/or modify it at will.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  
*/

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <ctime>
#include "data.h"
#include "simplex.h"
#include "pretty_print.h"
using namespace std;

extern double spectrum_RSS(vector<double>);

int main(int argc, char* argv[]){
	using Measurement::ReadDataXY;
	ReadDataXY("data.txt");

	double parameters[6] =  {1.0, 33.0, 445.0, 1.0, 55.0, 0.0001};
	vector<double> init(parameters, parameters+6);

	using BT::Simplex;
	cout << "The fitted parameters using nonlinear-least-square are: " << endl;
	printcon( Simplex(spectrum_RSS, init, 1e-11) );
}
