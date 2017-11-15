/**
*
*CS372: Lab8
*File: dijkstra.h
*Author: August B. Sandoval
*Purpose: the header for dijkstra static class definition
*
**/
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Graph.h"
#include "Node.h"

class dijkstra {

public:
	static void Dijkstra_list(Graph & G, Node & s);
	static void Dijkstra_heap(Graph & G, Node & s);

};

#endif // !DIJKSTRA_H

