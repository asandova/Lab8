/**
*
*CS372:	Lab8
*File: Edge.cpp
*Author: August B. Sandoval
*Purpose: Defines the Edge class in Edge.h
*
**/
#include "Edge.h"

Edge::Edge(){
	Dist = numeric_limits<double>::infinity();
	Dest = nullptr;
	Src = nullptr;
}

void Edge::Destination(Node& D){
	Dest = &D;
}

void Edge::Distance(double d){
	Dist = d;
}
void Edge::Source(Node & s) {
	Src = &s;
}

Node& Edge::getSource()const{
	return *Src;
}

Node& Edge::getDestination()const{
	return *Dest;
}
double Edge::getDistance()const{
	return Dist;
}