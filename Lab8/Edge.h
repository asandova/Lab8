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
class Edge
{
public:
	Edge(const int s,const int d, double dist);
	int getSource()const;
	int getDestination()const;
	void setDistance(double d);
	double getDistance()const;
	friend ostream& operator<<(ostream& out, const Edge& E);
	bool operator==(const Edge& E)const;
	bool operator!=(const Edge& E)const;
private:
	double Dist;
	const int DestID;
	const int SrcID;
};

#endif // !EDGE_H



