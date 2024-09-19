
#ifndef SIMCITY_H
#define SIMCITY_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "loc.h"
#include "Residential.h"
using namespace std;

void readInput(string layout, vector<vector<loc>> &region);
void outCSV(vector<vector<loc>> &region);
//int totPop(vector<vector<loc>> region);
void update(vector<vector<loc>> &region);
//void print(vector<vector<loc> >& arr, int step, int limit);


#endif // !READCSV_H

