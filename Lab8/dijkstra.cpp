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
#include <fstream>

void PathOut(vector<int>& path, Graph& g);

void dijkstra::Dijkstra_list(Graph & G, Node & s) {

	//creating the prioity queue starting with source
	LinkedPQueue H = LinkedPQueue(s, G.getAllNodes());

	while (!H.isEmpty()) {
		Node u = H.Front();
		H.RemoveMin();
		list<Edge>::iterator e;
		for (e = G.getAdjNodes(u).begin(); e != G.getAdjNodes(u).end(); ++e ) {
			if (G.getNodeAt(e->getDestination()).Dist() > u.Dist() + e->getDistance()) {
				G.getNodeAt(e->getDestination()).setDist(u.Dist() + e->getDistance());
				G.getNodeAt(e->getDestination()).setPreID( u.id() );
				H.decreaseKey( G.getNodeAt( e->getDestination() ) , u.Dist() + e->getDistance() );
			}
		}
	}
}

void dijkstra::Dijkstra_heap(Graph & G, Node & s) {
	//creating the prioity queue starting with source
	MinHeapQueue H = MinHeapQueue(s, G.getAllNodes() );

	while (!H.isEmpty()) {
		Node u = H.Front();
		H.RemoveMin();
		list<Edge>::const_iterator e;
		for (e = G.getAdjNodes(u).begin(); e != G.getAdjNodes(u).end(); ++e) {
			if (G.getNodeAt(e->getDestination()).Dist() > ( u.Dist() + e->getDistance() ) ) {
				G.getNodeAt(e->getDestination()).setDist(u.Dist() + e->getDistance());
				G.getNodeAt(e->getDestination()).setPreID(u.id());
				H.decreaseKey(G.getNodeAt(e->getDestination()), u.Dist() + e->getDistance() );
			}
		}
	}
}

void dijkstra::Dijkstra_EC(Graph & G, Node & s, Node & d) {
	//creating the prioity queue starting with source
	s.setDist(0);
	MinHeapQueue H = MinHeapQueue(s, G.getAllNodes());
	vector<int> rpath = vector<int>();

	while (!H.isEmpty()) {
		Node u = H.Front();
		H.RemoveMin();
		list<Edge>::const_iterator e;
		for (e = G.getAdjNodes(u).begin(); e != G.getAdjNodes(u).end(); ++e) {
			Node t = G.getNodeAt(e->getDestination());
			//if ((s.Lat() <= t.Lat() && t.Lat() <= d.Lat()) && (s.Long() <= t.Long() && t.Long() <= d.Long())) {
				if (G.getNodeAt(e->getDestination()).Dist() > (u.Dist() + e->getDistance())) {
					G.getNodeAt(e->getDestination()).setDist(u.Dist() + e->getDistance());
					G.getNodeAt(e->getDestination()).setPreID(u.id());
					H.decreaseKey(G.getNodeAt(e->getDestination()), u.Dist() + e->getDistance());
				}
				if (G.getNodeAt(e->getDestination()) == d) {
					cout << "destination found" << endl;
					rpath.push_back(d.id());
					while (rpath.back() != s.id()) {
						rpath.push_back(G.getNodeAt(rpath.back()).PreID());
					}
					cout << "printing path to file" << endl;
					PathOut(rpath, G);
					return;
				}
			//}
		}
	}

}

void PathOut(vector<int>& path , Graph& g) {

	ofstream OFile;
	double totalDist = 0;
	OFile.open( "EC_Path.txt", ios::out);
	for (vector<int>::reverse_iterator itr = path.rbegin(); itr != path.rend(); ++itr) {
		OFile << g.getNodeAt(*itr).name() << " " << g.getNodeAt(*itr).Lat() << " " << g.getNodeAt(*itr).Long() << endl;
	}
	OFile << "Total Distance (Miles): " << g.getNodeAt( path.front() ).Dist() << endl;
	OFile.close();
}