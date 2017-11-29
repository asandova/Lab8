/**
*
*CS372:	Lab8
*File: Edge.h
*Author: August B. Sandoval
*Purpose: Provides the class definition of  class Edge
*
**/
#ifndef EDGE_H
#define EDGE_H

#include "Node.h"
#include <iostream>

class Edge
{
public:
	Edge(int s,int d, double dist);
	int getSource()const;
	int getDestination()const;
	void setDistance(double d);
	double getDistance()const;
	friend ostream& operator<<(ostream& out, const Edge& E);
	bool operator==(const Edge& E)const;
	bool operator!=(const Edge& E)const;
private:
	double Dist;
	int DestID;
	int SrcID;
};

#endif // !EDGE_H



