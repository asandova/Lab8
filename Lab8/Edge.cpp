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
}

void Edge::Destination(Node& D){
	Dest = &D;
}

void Edge::Distance(double d){
	Dist = d;
}
Node& Edge::getDestination() {
	return *Dest;
}
double Edge::getDistance() {
	return Dist;
}