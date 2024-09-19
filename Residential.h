
#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H
#include <iostream>
#include "loc.h"
using namespace std;

vector<loc> isAdj(vector <vector<loc>> &arr, int i, int j);
bool isValidPos(int i, int j, int n, int m);
bool findRegionType(string type, vector<vector<loc>> region, int x, int y);
vector<vector<loc>> updateRes(vector<vector<loc>>& arr);

//void adjPrint(vector<loc> x);

#endif // !
