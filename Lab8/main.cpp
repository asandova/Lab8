/**
*
*CS372: Lab8
*File: main.cpp
*Author: August B. Sandoval
*Purpose: The main file for Lab8
*
**/
#include <iostream>
#include <string>

#include "Node.h"
#include "Graph.h"
#include "dijkstra.h"

using namespace std;

// [[Rcpp::export]]
void wrapList(string& filename) {
	Graph test = Graph(filename, true);
	dijkstra::Dijkstra_list(test,test.getNode(0));
}
// [[Rcpp::export]]
void wrapHeap(string& filename) {
	Graph test = Graph(filename, true);
	dijkstra::Dijkstra_heap(test, test.getNode(0));
}

void testall(){

	Graph Tgraph("Graph1.txt",true);
	Graph Tgraph1("Graph1-1.txt", true);
	//Graph Tgraph2("Lab8_Test.txt", true);
	cout << Tgraph << endl;
	dijkstra::Dijkstra_heap(Tgraph, Tgraph.getNode(0));
	cout << Tgraph << endl;

	//cout << Tgraph1 << endl;
	dijkstra::Dijkstra_heap(Tgraph1, Tgraph.getNode(0));
	cout << Tgraph1 << endl;

	//cout << Tgraph2 << endl;
	//dijkstra::Dijkstra_list(Tgraph2, Tgraph2.getNode(0));
	//cout << Tgraph2 << endl;

	//extra credit
	/*
	Graph ECGraph = Graph();
	ECGraph.scanTMG("USA-country-simple.tmg");
	ECGraph.save("EC_master.txt");
	cout << "read complete" << endl;
	int S_ID = ECGraph.findID("NM271@+X478507");
	int E_ID = ECGraph.findID("US11_N/NY11C_N");
	//dijkstra::Dijkstra_EC(ECGraph, ECGraph.getNodeAt(S_ID) , ECGraph.getNodeAt(E_ID));
	*/
}

int main(){

    testall();
    
    return 0;
}

/*** R

require("igraph")
source("random_graph.R")
print("working")
edges.num <- c(1000,1100,1200,1300,1400)
nodes.num <- c(1000,1100,1200,1300,1400)
runtime <- vector(length = 5)
for(i in c(1:5)){
 #random.graph(nodes.num[i], edges.num[i], "Lab8_Test.txt")

  #runtime[i] <- system.time(wrapList("Lab8_Test.txt") )["user.self"]
  #runtime[i] <- system.time(wrapHeap("Lab8_Test.txt") )["user.self"]
  
}
  #plot( nodes.num ,runtime, type="b", xlab="Nodes", ylab = "runtime (seconds)")
  print("done")
*/
