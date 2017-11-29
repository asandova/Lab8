/**
*
*CS372:	Lab4, Lab5, Lab6
*File: Graph.cpp
*Author: August B. Sandoval
*Purpose: Defines the Graph class in Graph.h
*
**/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <cstring>
#include <math.h>
#include <stdlib.h>

#include "Graph.h"
using namespace std;

Graph::Graph() {
	Directed = false;
	m_nodes = vector<Node>();
	m_adjList = vector<list<Edge> >();
}

Graph::Graph(const string & file, bool dir){
    Directed = dir;
    m_nodes = vector<Node>();
    m_adjList = vector<list<Edge> >();
    scan(file);
}

Graph::Graph(const string& file){
    Directed = false;

    m_nodes = vector<Node>();
    m_adjList = vector<list<Edge> >();
    scan(file);
}

bool Graph::isDirected()const {
	return Directed;
}

void Graph::setDirect(bool dir) {
	Directed = dir;
}
/*
void Graph::update(){
	for (size_t i = 0; i < m_nodes.size(); i++) {
		for (list<Edge>::iterator itr = m_adjList[i].begin(); itr != m_adjList[i].end(); ++itr) {
			*itr = getNode(itr->id());
		}
	}
}
*/
//Insert a edge ( a ,b ) to m_adjList
void Graph::addEdge ( const Node & a , const Node & b, double d ) {
    //the addEdge will add node b to node a's adj list if
        //the node is not already in the list
            //and inserts the nodes in alphabetical order
	//cout << "adding edge:" << a << " to " << b << endl;
    if(!NodeExistAdj( b, a.id() ) ){
        //list<Node*> adjList = getAdjNodes(a);
        m_adjList[a.id()].push_back( Edge(a.id(), b.id(), d ) );
		if (Directed)
			return;
    }
	//cout << "edge " << a << " to " << b << " already exists" << endl;
	//adds the edge from B to A if the graph is undirected
    if(!Directed){
		if (!NodeExistAdj(a, b.id())) {
			m_adjList[b.id()].push_front(Edge(b.id(), a.id(), d));
			//cout << "created edge: " << b << " to " << a << endl;
		}
	}//end of if directed
}//end of add edge

//Insert a node a to m_nodes
void Graph::addNode ( const Node & a ) {
    ///add the node to the Graph's node vector
    ///if the node does not already exist
    //checking is the node is already in the vector
	//cout << "adding Node " << a << endl;
    if( !NodeExist(a.name() ) ){
		//creating adjecency list for new Node
		list<Edge> adj = list<Edge>();
		m_adjList.push_back(adj);
		m_nodes.push_back(a);
    }
}

bool Graph::NodeExistAdj(const Node& a, size_t id)const{
    ///checks if node a is in the adj list for the node with the ID value of id
    const list<Edge> Adjlist = getAdjNodes( getNode(id) );
    for(list<Edge>::const_iterator itr = Adjlist.begin(); itr != Adjlist.end(); ++itr ){
        if(a == getNode(itr->getDestination()) )
            return true;
    } 
    return false;
}

bool Graph::NodeExist(const string& name)const{
	if (m_nodes.empty()) { return false; }
    Node curr;
    for(size_t i = 0; i < m_nodes.size(); i++){
        curr = getNode(i);
        if(curr.name() == name){
            return true;
        }
    }
    return false;
}

size_t Graph::findID(const string & name)const{

    Node curr;
    for(size_t i = 0; i < m_nodes.size(); i++){
        curr = getNodeAt(i);
        if(curr.name() == name){
            return curr.id();
        }
    }
    return -1;
}

// Return node with id equal to i
//The deviation from the original for getNode is insure the correct node is returned
//even when m_node is sorted alphabetically
//However it does increase the runtime from constant to linear
const Node & Graph::getNode ( size_t id )const{

	if(id == m_nodes[id].id()  )
		return m_nodes[id];

	for (size_t i = 0; i < m_nodes.size(); i++ ) {
		if (m_nodes[i].id() == id)
			return m_nodes[i];
	}
	//should never get here
	return Node::NULL_NODE;
}

Node & Graph::getNode(size_t id) {
	if (id == m_nodes[id].id())
		return m_nodes[id];

	for (size_t i = 0; i < m_nodes.size(); i++) {
		if (m_nodes[i].id() == id)
			return m_nodes[i];
	}
	//should never get here
	return m_nodes[0];
}

Node& Graph::getNodeAt(size_t i) {
	return m_nodes[i];
}

const Node& Graph::getNodeAt(size_t i)const {
	return m_nodes[i];
}

// Return reference of the adjacency list of node a
list <Edge> & Graph::getAdjNodes ( const Node & a ){
    return m_adjList[ a.id ( ) ] ;
}

// Return constant reference to adjacency list of node a
const list <Edge> & Graph::getAdjNodes ( const Node & a ) const{
    return m_adjList [ a.id ( ) ] ;
}

vector<Node>& Graph::getAllNodes() {
	return m_nodes;
}

// Return the total number of nodes i n the graph
size_t Graph::num_nodes ( ) const {
    return m_nodes.size( ) ;
}

//only splits strings into two on tab character
vector<string> split(const string& a){
    vector<string> Line;
	size_t TabLoc[2];
	size_t tab = 0;
    for(size_t i = 0; i < a.size()-1; i++ ){
        if(a[i] == '\t' || a[i] == ' ' && tab < 2){
			TabLoc[tab] = i;
			tab++;
        }
    }
	Line.push_back( a.substr(0,TabLoc[0]) );
	Line.push_back( a.substr(TabLoc[0]+1,TabLoc[1]-TabLoc[0]-1) );
	Line.push_back(a.substr(TabLoc[1]+1, a.size() ) );
    return Line;
}

vector<string> split2(const string& a) {
	vector<string> Line;
	//size_t TabLoc[2];
	size_t tab = 0;
	for (size_t i = 0; i < a.size() - 1; i++) {
		if (a[i] == ' ' || a[i] == '\t') {
			Line.push_back(a.substr(0, i));
			Line.push_back(a.substr(i + 1, a.size()));
			break;
		}
	}
	return Line;
}

// Create a graph from a tab−separated text edge list file
// to adjacency lists
void Graph::scan ( const string & file ){
	if (!m_nodes.empty()) {
		m_nodes.clear();
		m_adjList.clear();
	}
    //char* line;
    string fline;
    int id = 0;
    Node N1, N2;
    ifstream iFile;
    iFile.open( file.c_str(), ifstream::in );
    if(  iFile.is_open()  ){
        while( !iFile.eof() ){
                getline(iFile, fline);
                string L(fline);
				if (fline.size() >= 3) {
					vector<string> Line = split(fline);
					//vector<string>names(2);
					//names[0] = fline.c_str()[0];
					//names[1] = fline.c_str()[2];
					//cout << endl <<"read in: "<< fline << endl;

					if(!NodeExist( Line[0] ) ){
							N1 = Node( Line[0],id++) ;
							//N1 = tmp1;
							addNode(N1);
					}else{
						//cout << "Node with name " << names[0] << " exist" << endl;
						N1 = getNode( findID( Line[0] ) ) ;
						//cout << "Existing: N1-" << N1 << endl;
					}
					//cout << "N1: " << N1 << endl;
					if(!NodeExist( Line[1] ) ){
							N2 = Node( Line[1] ,id++);
							//N2 = tmp2;
							addNode( N2 ) ;
					}else{
							//cout << "Node with name" << names[1] << " exist" << endl;
							N2 = getNode( findID( Line[1] ) ) ;
					}
					//cout << "N2: " << N2 << endl;
					//cout << N1 << endl << N2 << endl;
					addEdge(N1, N2, atof( Line[2].c_str() ));
				}
        }//end of while
        iFile.close();
    }else{
        cout << "File: " << file << " does not exist" << endl;
    }//end of else
}//end of scan

void Graph::scanTMG(const string& file) {
	string fline;
	ifstream iFile;

	iFile.open(file.c_str(), ifstream::in);
	int line = 0;
	int numVert = 0;
	int numEdges = 0;
	vector<string> tline;
	if (iFile.is_open()) {
		while (!iFile.eof()) {
			getline(iFile, fline);
			
			if (line > 0) {
				if (line == 1) {
					tline = split2(fline);
					numVert = atoi(tline[0].c_str());
					numEdges = atoi(tline[1].c_str());
					m_nodes.reserve(numVert);
				}
				else if (line >= 2 && line < numVert + 2 ) {
					tline = split(fline);
					list<Edge> adj = list<Edge>();
					m_adjList.push_back(adj);
					m_nodes.push_back( Node(tline[0], line - 2, atof(tline[1].c_str()), atof(tline[2].c_str() ) ) );

					//addNode( Node(tline[0], line - 2, atof( tline[1].c_str() ), atof(tline[2].c_str() ) ) );
				}
				else if (line >= numVert + 2){
					tline = split(fline);
					int N1ID = atoi(tline[0].c_str());
					int N2ID = atoi(tline[1].c_str());
					addEdge(getNodeAt(N1ID), getNodeAt(N1ID), findDist(getNodeAt(N1ID), getNodeAt(N2ID)));
				}
				//cout << fline << endl;
			}
			line++;
		}
		iFile.close();
	}
	else {
		cout << "cannot open file" << endl;
	}

}

// Save a graph from adjacency lists to a tab−separated
// text edge list file
void Graph::save( const string & file ){
    //NOTE: the method assumes the file does not exist and will overwrite
    // if the file does exist
        //cout << "in save" << endl;
        ofstream OFile;
        OFile.open(file.c_str(), ofstream::out);
        for(size_t i =0; i < m_nodes.size(); i++){
			const list<Edge> neighbors = getAdjNodes(getNode(i));
			for (list<Edge>::const_iterator itr = neighbors.begin(); itr != neighbors.end(); ++itr){
				list<Edge>::const_iterator Nitr = itr;
				if ( i + 1 == m_nodes.size() && ++Nitr == neighbors.end()){
					OFile << getNodeAt(i).name() << "\t" << getNode(itr->getDestination()).name()  << "\t" << itr->getDistance();
				}
				else {
					OFile << getNodeAt(i).name() << "\t" << getNode(itr->getDestination()).name() << "\t" << itr->getDistance() << "\n";
				}
			}
        }
        OFile.close();
}

ostream& operator<<(ostream & out, const Graph & g){
    out << "Nodes in "<< ( ( g.Directed )? "Directed" : "Undirected") << " graph: " << endl ;
	out << "Nodes: ";
	for (unsigned i = 0; i < g.num_nodes(); i++) {
		if (i + 1 == g.num_nodes()) {
			out << g.m_nodes[i].name() << "(" << g.m_nodes[i].Dist() << ")" ;
		}
		else {
		out << g.m_nodes[i].name() << "(" << g.m_nodes[i].Dist() << "), ";
		}
    }
	out << endl;
    out << "Adjacency list of the graph : " << endl ;
    for ( unsigned i =0; i <g.num_nodes( ) ; i ++) {
        out << "Node " << g.m_nodes[i].name( ) << " : ";
        const list <Edge> neighbors = g.getAdjNodes ( g.m_nodes[i]) ;
            for( list<Edge>::const_iterator itr = neighbors.begin( ) ;
                itr!= neighbors.end( ) ; ++itr ) {
				list<Edge>::const_iterator BEnd = itr;
				if (++BEnd == neighbors.end()) {
					out << g.getNode(itr->getDestination()).name()<< "-" << itr->getDistance();
				}else
					out << g.getNode(itr->getDestination()).name()<< "-" << itr->getDistance() <<", " ;
            }
        out << endl;
    }
    return out;
}

double Graph::findDist( Node & a, Node& b)const {
	double latDif, LongDif, A, C;
	latDif = b.Lat() - a.Lat();
	LongDif = b.Long() - a.Long();
	A = pow(sin(latDif / 2), 2) + cos(a.Lat()) * cos(b.Lat()) * pow(sin(LongDif / 2), 2);
	C = 2 * atan2(sqrt(A), sqrt( 1 - A ));
	return 3961 * C;
}

