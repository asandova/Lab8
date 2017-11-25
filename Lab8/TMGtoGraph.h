#pragma once
#ifndef TMGTOGRAPH_H
#define TMGTOGRAPH_H
#include <string>

using namespace std;

class TMGtoGraph{

public:
	static void toGraph(const string & fname);
	static double findDistance(double l, double lat);
};
#endif // !TMGTOGRAPH_H
