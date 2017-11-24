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

using namespace std;

void testall(){

	Graph Tgraph("Graph1.txt");
	cout << Tgraph << endl;
}

int main(){

    testall();
    
    return 0;
}

/*** R

require("igraph")
source("random_graph.R")
source("main.cpp")
#edges.num <- c(100,100,100,100,100)
#nodes.num <- c(10000,12500,15000,17500,20000)
 #edges.num <- c(100)
 #nodes.num <- c(100)
runtime <- vector(length = 1)
for(i in c(1:1)){
 random.graph(nodes.num[i], edges.num[i], "Lab6_Test.txt")

  #links <- read.table("Lab6_Test.txt", header = F, quote = "", stringsAsFactors = F)
  #names(links) <- c("from", "to")
  #links <- data.frame( from=c("a", "a", "c", "d", "e" ),
  #                                         to = c("d", "b", "b", "c", "a"))
  #net <- graph_from_data_frame(d=links, directed=T)
  #plot(net, vertex.size=30, vertex.label.cex=2)

  #net <- graph_from_data_frame(d=links, directed=F)
  #plot(net, vertex.size=30,vertex.label.cex=2)

  runtime[i] <- system.time(wrapStrCon("Lab6_Test.txt") )["user.self"]
  plot( 20 ,runtime, type="b", xlab="n", ylab = "runtime (seconds)")
 
}
 
*/
