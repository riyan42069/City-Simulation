#include "Residential.h"
using namespace std;

//vector<loc> isAdj(vector <vector<loc>> &region, int x, int y)
//{
//	vector<loc> adj;
//	/*for (int i = 0; i < region.size(); i++)
//	{
//		for (int j = 0; j < region[i].size(); j++)
//		{*/
//			if (x <= region.size())
//			{
//				if (x + 1 <= region.size())
//				{
//					adj.push_back(region[x + 1][y]);
//					if (y + 1 <= region[x].size())
//					{
//						adj.push_back(region[x + 1][y + 1]);
//					}
//					if (y - 1 >= 0)
//					{
//						adj.push_back(region[x + 1][y - 1]);
//					}
//				}
//				if (x - 1 >= 0)
//				{
//					adj.push_back(region[x - 1][y]);
//					if (y + 1 <= region[x].size())
//					{
//						adj.push_back(region[x - 1][y + 1]);
//					}
//					if (y - 1 >= 0)
//					{
//						adj.push_back(region[x - 1][y - 1]);
//					}
//				}
//				if (y + 1 <= region[x].size())
//				{
//					adj.push_back(region[x][y + 1]);
//				}
//				if (y - 1 >= 0)
//				{
//					adj.push_back(region[x][y - 1]);
//				}
//			}
//		//}
//	//}
//	return adj;
//}

bool isValidPos(int i, int j, int n, int m)
{
	if (i<0 || j<0 || i >n - 1 || j >m - 1)
	{
		return 0;
	}
	return 1;

}

vector<loc> isAdj(vector <vector<loc>>& arr, int i, int j)
{
	int n = arr.size();
	int m = arr[0].size();


	vector<loc> v;
	if (isValidPos(i - 1, j - 1, n, m))
		v.push_back(arr[i - 1][j - 1]);
	if (isValidPos(i - 1, j, n, m))
		v.push_back(arr[i - 1][j]);
	if (isValidPos(i - 1, j + 1, n, m))
		v.push_back(arr[i - 1][j + 1]);
	if (isValidPos(i, j - 1, n, m))
		v.push_back(arr[i][j - 1]);
	if (isValidPos(i, j + 1, n, m))
		v.push_back(arr[i][j + 1]);
	if (isValidPos(i + 1, j - 1, n, m))
		v.push_back(arr[i + 1][j - 1]);
	if (isValidPos(i + 1, j, n, m))
		v.push_back(arr[i + 1][j]);
	if (isValidPos(i + 1, j + 1, n, m))
		v.push_back(arr[i + 1][j + 1]);

	return v;
}

//vector<loc> isAdj(vector <vector<loc>>& region, int x, int y) {
//	vector<loc> adj;
//	for (int i = 0; i < region.size(); i++) {
//		for (int j = 0; j < region[i].size(); j++) {
//			if (i < region.size()) {
//				if (i + 1 < region.size()) {
//					adj.push_back(region[i + 1][j]);
//				}
//
//				if (i - 1 >= 0) {
//					adj.push_back(region[i - 1][j]);
//				}
//			}
//			if (j < region[i].size()) {
//				if (j - 1 >= 0) {
//					adj.push_back(region[i][j - 1]);
//
//					if (i - 1 >= 0) {
//						adj.push_back(region[i - 1][j - 1]);
//					}
//					if (i + 1 < region.size()) {
//						adj.push_back(region[i + 1][j - 1]);
//					}
//				}
//
//				if (j + 1 < region[i].size()) {
//					adj.push_back(region[i][j + 1]);
//					if (i - 1 >= 0) {
//						adj.push_back(region[i - 1][j + 1]);
//					}
//					if (i + 1 < region.size()) {
//						adj.push_back(region[i + 1][j + 1]);
//					}
//				}
//			}
//		}
//	}
//	return adj;
//}


bool findRegionType(string type, vector<vector<loc>> region, int x, int y)
{
	bool dec = true;
	vector<loc> temp = isAdj(region, x, y);
	for (int i = 0; i < temp.size(); i++)
	{
		if (type == temp[i].regionType)
		{
			dec = true;
		}
		else
		{
			dec = false;
		}
		break;
	}
	return dec;
}

vector<vector<loc>> updateRes(vector<vector<loc>> &arr)
{
	vector<vector<loc>> region = arr;
	for (int i = 0; i < region.size(); i++)
	{
		for (int j = 0; j < region[i].size(); j++)
		{
			if (region[i][j].regionType == "R")
			{
				if (region[i][j].population == 0)
				{
					vector<loc> temp = isAdj(region, i, j);
					for (int x = 0; x < temp.size(); x++)
					{
						bool decision = findRegionType("#", region, i, j);
						decision  =	findRegionType("T", region, i, j);
						if (decision == true)
						{
							region[i][j].population++;
							break;
						}
					}
					
					int counter = 0;
					for (int x = 0; x < temp.size(); x++)
					{
						if (temp[x].population >= 1)
						{
							counter++;
						}
						if (counter >= 1)
						{
							region[i][j].population++;
							break;
						}
					}
				}

				else if (region[i][j].population == 1)
				{
					int counter = 0;
					vector<loc> temp = isAdj(region, i, j);
					for (int x = 0; x < temp.size(); x++)
					{
						if (temp[x].population >= 1)
						{
							counter++;
							if (counter == 2)
							{
								region[i][j].population++;
								break;
							}
						}
					}
				}

				else if (region[i][j].population == 2)
				{
					int counter = 0;
					vector<loc> temp = isAdj(region, i, j);
					for (int x = 0; x < temp.size(); x++)
					{
						if (temp[x].population >= 2)
						{
							counter++;
							if (counter == 4)
							{
								region[i][j].population++;
								break;
							}
						}
					}
				}

				else if (region[i][j].population == 3)
				{
					int counter = 0;
					vector<loc> temp = isAdj(region, i, j);
					for (int x = 0; x < temp.size(); x++)
					{
						if (temp[x].population >= 3)
						{
							counter++;
							if (counter == 6)
							{
								region[i][j].population++;
								break;
							}
						}
					}
				}

				else if (region[i][j].population == 4)
				{
					int counter = 0;
					vector<loc> temp = isAdj(region, i, j);
					for (int x = 0; x < temp.size(); x++)
					{
						if (temp[x].population >= 4)
						{
							counter++;
							if (counter == 8)
							{
								region[i][j].population++;
								break;
							}
						}
					}
				}
			}
		}
	}
	return region;
}

