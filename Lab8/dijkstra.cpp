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
#include "HeapPriorityQueue.cpp"
#include "LinkedPriorityQueue.h"
#include "LinkedPriorityQueue.cpp"


void dijkstra::Dijkstra_list(Graph & G, Node & s) {

	//creating the prioity queue starting with source
	LinkedPQueue<Node> H = LinkedPQueue<Node>(s);

	while (!H.isEmpty()) {
		Node u = H.Front();
		H.RemoveMin();
		list<Edge>::iterator e;
		for (e = G.getAdjNodes(u).begin(); e != G.getAdjNodes(u).end(); ++e ) {
			if (G.getNodeAt(e->getDestination()).Dist() > u.Dist() + e->getDistance()) {
				G.getNodeAt(e->getDestination()).setDist(u.Dist() + e->getDistance());
				G.getNodeAt(e->getDestination()).setPreID( u.id() );
				H.decreaseKey(  );
			}
		}
	}
}

void dijkstra::Dijkstra_heap(Graph & G, Node & s) {
	//creating the prioity queue starting with source
	MinHeapQueue<Node> H = MinHeapQueue<Node>(s);

	while (!H.isEmpty()) {
		Node u = H.Front();
		H.RemoveMin();
		list<Edge>::iterator e;
		for (e = G.getAdjNodes(u).begin(); e != G.getAdjNodes(u).end(); ++e) {
			if (G.getNodeAt(e->getDestination()).Dist() > u.Dist() + e->getDistance()) {
				G.getNodeAt(e->getDestination()).setDist(u.Dist() + e->getDistance());
				G.getNodeAt(e->getDestination()).setPreID(u.id());
				H.decreaseKey();
			}
		}
	}
}