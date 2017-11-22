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
	Edge();
	void Destination(Node& dest);
	void Distance(double dist);
	Node& getDestination();
	double getDistance();
private:
	double Dist;
	Node* Dest;
};

#endif // !EDGE_H



