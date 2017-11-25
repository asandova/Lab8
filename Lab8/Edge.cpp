/**
*
*CS372:	Lab8
*File: Edge.cpp
*Author: August B. Sandoval
*Purpose: Defines the Edge class in Edge.h
*
**/
#include "Edge.h"

Edge::Edge(const int s,const int d, double dist):DestID(d),SrcID(s) {
	Dist = dist;
}

void Edge::setDistance(double d) {
	Dist = d;
}

int Edge::getSource()const{
	return SrcID;
}

int Edge::getDestination()const{
	return DestID;
}
double Edge::getDistance()const{
	return Dist;
}

bool Edge::operator==(const Edge& E)const {
	//returns true of the edge is connected to the same nodes regardless of which is the source and destination
	//the reason is that it is the same edge in a indirected graph
	//if returns false of the end node are different
	if ( this->DestID == E.getDestination() && this->SrcID == E.getSource()) {
		return true;
	}
	else if ( this->SrcID == E.getDestination() && this->DestID == E.getSource()) {
		return true;
	}
	else {
		return false;
	}
}
bool Edge::operator!=(const Edge& E)const {
	if (*this == E) {
		return false;
	}
	else {
		return true;
	}
}