//data.cpp {O}
#include "data.h"
#include <fstream>
#include <iostream>
namespace Measurement
{
	std::vector<double> dataX;
	std::vector<double> dataY;

	void ReadDataXY(std::string filename)
	{
		using namespace std;
		ifstream datafile(filename.c_str());
		if(!datafile)
		{
			std::cerr << filename << ": no such file exist" << endl;
		}

		double x,y;
		while(datafile>>x, datafile>>y, !datafile.eof())
		{
			dataX.push_back(x);
			dataY.push_back(y);
		}
		datafile.close();
	}
}
