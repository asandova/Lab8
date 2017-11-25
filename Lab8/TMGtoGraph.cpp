#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include "TMGtoGraph.h"


using namespace std;

struct LongLat {
	double Long;
	double Lat;
};

vector<string> split2(const string& a) {
	vector<string> Line;
	size_t TabLoc[2];
	size_t tab = 0;
	for (size_t i = 0; i < a.size() - 1; i++) {
		if (a[i] == ' ' && tab < 2) {
			TabLoc[tab] = i;
			tab++;
		}
	}
	Line.push_back(a.substr(0, TabLoc[0]));
	Line.push_back(a.substr(TabLoc[0] + 1, TabLoc[1] - TabLoc[0] - 1));
	Line.push_back(a.substr(TabLoc[1] + 1, a.size()));
	return Line;
}
vector<string> split3(const string& a) {
	vector<string> Line;
	size_t TabLoc[2];
	size_t tab = 0;
	for (size_t i = 0; i < a.size() - 1; i++) {
		if (a[i] == ' ') {
			Line.push_back( a.substr(0, i) );
			Line.push_back(a.substr(i + 1, a.size()));
			break;
		}
	}
	return Line;
}

void TMGtoGraph::toGraph(const string & fname){
	string fline;
	ifstream iFile;
	vector<LongLat> coords = vector<LongLat>();

	iFile.open(fname.c_str(), ifstream::in);
	int line = 0;
	int numVert = 0;
	int numEdges = 0;
	if (iFile.is_open()) {
		while (!iFile.eof()) {
			getline(iFile, fline);
			if (line == 2 ) {
				vector<string> nums = split2(fline);
				numVert = atof(nums[0].c_str());
				numEdges = atof(nums[1].c_str());
				coords.reserve(numVert);
			}
			else if (line < numVert + 2) {

			}
			else {
				
			}

			//cout << fline << endl;
		}
		iFile.close();
	}
	else{
		cout << "cannot open file" << endl;
	}

}
double TMGtoGraph::findDistance(double l, double lat) {

}
