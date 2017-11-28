/**
*
*CS372: Lab8
*File: dijkstra.cpp
*Author: August B. Sandoval
*Purpose: implements dijkstra static class
*
**/

#include "dijkstra.h"
#include "HeapPriorityQueue.h"
#include "LinkedPriorityQueue.h"


void dijkstra::Dijkstra_list(Graph & G, Node & s) {

	//creating the prioity queue starting with source
	LinkedPQueue H = LinkedPQueue(s);

	while (!H.isEmpty()) {
		Node u = H.Front();
		H.RemoveMin();
		list<Edge>::iterator e;
		for (e = G.getAdjNodes(u).begin(); e != G.getAdjNodes(u).end(); ++e ) {
			if (G.getNodeAt(e->getDestination()).Dist() > u.Dist() + e->getDistance()) {
				//G0getNodeAt(e->getDestination()).setDist(u.Dist() + e->getDistance());
				G.getNodeAt(e->getDestination()).setPreID( u.id() );
				H.decreaseKey( G.getNodeAt( e->getDestination() ) , u.Dist() + e->getDistance() );
			}
		}
	}
}

void dijkstra::Dijkstra_heap(Graph & G, Node & s) {
	//creating the prioity queue starting with source
	MinHeapQueue H = MinHeapQueue(s);

	while (!H.isEmpty()) {
		Node u = H.Front();
		H.RemoveMin();
		list<Edge>::iterator e;
		for (e = G.getAdjNodes(u).begin(); e != G.getAdjNodes(u).end(); ++e) {
			if (G.getNodeAt(e->getDestination()).Dist() > u.Dist() + e->getDistance()) {
				G.getNodeAt(e->getDestination()).setDist(u.Dist() + e->getDistance());
				G.getNodeAt(e->getDestination()).setPreID(u.id());
				H.decreaseKey(G.getNodeAt(e->getDestination()), u.Dist() + e->getDistance() );
			}
		}
	}
}