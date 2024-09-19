#include "simcity.h"
#include <vector>
#include <iostream>
using namespace std;

void readInput(string layout, vector<vector<loc>> &region)// function to read the data from the file
{
	ifstream regionFile(layout);

	// storing region file data in 2d array
	char storedChar;
	int rowNumber = 0;

	regionFile >> noskipws;

	// add each cell to the array
	while (regionFile >> storedChar) {
		vector<loc> newRow;
		region.push_back(newRow);
		while (storedChar != '\n') {
			if (storedChar != ',') {
				loc newCell;
				newCell.regionType = storedChar;
				region.at(rowNumber).push_back(newCell);
			}
			regionFile >> storedChar;
		}
		rowNumber++;
	}

	// print initial state
	cout << "Initial State" << endl;
	//print(region, 0, 1);
	outCSV(region);

}

void update(vector<vector<loc>> &arr)
{
	arr = updateRes(arr);
}


void outCSV(vector<vector<loc>> &region) // function to output data using given parameters
{
	//ofstream out(outFile);// creating a output stream to store the output in the file
	int pop = 0;// initializing the population as 0
	cout << region[0].size() << endl;
	for (int i = 0; i < region.size(); i++)// loop to acces every variable 
	{
		for (int j = 0; j < region[i].size(); j++)
		{
			if (region[i][j].population == 0)// checks if the region is populated
			{
				cout << 1 << " ";

			}
			else
			{
              cout << region[i][j].population << " ";
			  pop += region[i][j].population;
				
			}
			//adjPrint(isAdj(region, i, j));

		}
		cout << endl;
		//cout << "Available workers: " << workers << endl; // prints out the total number of workers and goods available in that particular timestep
		//cout << "Available goods: " << goods << endl;
		cout << "Total population: " << pop << endl;
	}
}

//void print(vector<vector<loc>>& arr, int step, int limit) {
//    int population = 0;
//    bool noPollution;
//    for (int i = 0; i < arr.size(); i++) {
//        for (int j = 0; j < arr[i].size(); j++) {
//            if (arr[i][j].population == 0) {
//                if (arr[i][j].pollution == 0)
//                    cout << (arr[i][j].regionType);
//                else
//                {
//                    if (arr[i][j].regionType != " ")
//                        cout << (arr[i][j].regionType);
//
//                }
//            }
//            else {
//                cout << arr[i][j].population;
//
//                //Add population to total population
//                population += arr[i][j].population;
//            }
//            if (arr[i][j].pollution > 0 && arr[i][j].regionType != "I")
//            {
//                if (arr[i][j].regionType == " ")
//                    cout << arr[i][j].pollution;
//                else
//                    cout << "(" << arr[i][j].pollution << ")";
//            }
//
//            cout.put(' ');
//
//        }
//        cout.put('\n');
//    }
//
//    //if printing out the final array
//    if (step > limit) {
//        cout << "Total Population: " << population << endl;
//    }
//}


