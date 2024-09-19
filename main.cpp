#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "simcity.h"
using namespace std;

int main()
{
	vector<vector<loc>> region;
	string regionLayout;// initializing the variable to store region file
	string tline;// temp file to slice the string and store the necessary data
	int timeLimit = 0;// initializing the variable to store the time limit
	int refreshRate;// initializing the variable 
	ifstream config("config1.txt"); // opening the config file

	if (!config.is_open())// checks if the file opens
	{
		cout << "File couldn't open!" << endl;
		exit(EXIT_FAILURE);// exits file if the file doesnt open
	}

	while (getline(config, tline))// loops while the stream can read an inout
	{
		size_t pos = tline.find("Region Layout:");// stores the position of the necessary data
		regionLayout = tline.substr(pos +14); //slices the data
		//cout << regionLayout << "\n";
		break;
	}
	while (getline(config, tline))
	{
		size_t pos = tline.find("Time Limit:");// stores the position of the necessary data
		timeLimit = stoi(tline.substr(pos + 11));//slices the data
		//cout << timeLimit << "\n";
		break;
	}
	while (getline(config, tline))
	{
		size_t pos = tline.find("Refresh Rate:");// stores the position of the necessary data
		refreshRate = stoi(tline.substr(pos + 13));//slices the data
		//cout << refreshRate << "\n";
		break;
	}
	config.close();
	

	int workers = 0;
	int goods = 0;
	int pollution = 0;


	readInput(regionLayout, region);

	for (int i = 0; i < timeLimit; i++)
	{
		update(region);
		//print(region, workers, timeLimit);
		//outCSV(regionLayout, workers, goods, region);
	}
	
	return 0;
}