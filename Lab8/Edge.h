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
	Edge(const Node& s, const Node &d, double dist);
	void Destination(Node& dest);
	void Distance(double dist);
	void Source(Node & src);
	Node& getSource()const;
	Node& getDestination()const;
	double getDistance()const;
private:
	double Dist;
	Node* Dest;
	Node* Src;
};

#endif // !EDGE_H



