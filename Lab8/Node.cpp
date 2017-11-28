/**
*
*CS372:	Lab4, Lab5, Lab6
*File: Node.cpp
*Author: August B. Sandoval
*Purpose: Defines the Node class in Node.h
*
**/
#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

const Node Node::NULL_NODE = Node();

Node::Node(){
    m_name = "NULL";
	dist = numeric_limits<double>::infinity();
	Latitude = 0.0;
	Longitude = 0.0;
}

Node::Node(const string & name, int id){
        m_name = name;
        m_id = id;
		dist = numeric_limits<double>::infinity();
}
Node::Node(const string & name, int id, double lat, double lon) {
	m_name = name;
	m_id = id;
	dist = numeric_limits<double>::infinity();
	Latitude = lat;
	Longitude = lon;
}


int Node::id()const{
    return m_id;
}

void Node::setID(int id){
    m_id = id;
}

const string & Node::name()const{
    return m_name;
}

void Node::setDist(double d) {
	dist = d;
}
double Node::Dist() const{
	return dist;
}

void Node::setPreID(int id) {
	preID = id;
}

int Node::PreID()const {
	return preID;
}

void Node::setLat(double l) {
	Latitude = l;
}
double Node::Lat()const{
	return Latitude;
}
void Node::setLong(double l) {
	Longitude = l;
}
double Node::Long()const{
	return Longitude;
}


//comparison operator overloading

ostream& operator<<(ostream & out, const Node & n){

    out << n.m_name << " " << n.m_id;
    return out;
}

bool Node::operator==(const Node& b)const{
    if( m_id == b.id()  && m_name == b.name() ){
        return true;
        }
    else
        return false;
}
bool Node::operator!=(const Node& b)const{
    return !(*this == b);
}

//operators <,> will to Lexicographical comparison based on ascii values
//so "a" < "b" because "a" = 97, "b"=98
//and "A" < "a" because "A" = 65, "a" = 97
/*
bool Node::operator<(const Node& b)const{
    if( m_name <  b.name() )
        return true;
    else
        return false;
}
bool Node::operator>(const Node & b)const {
    if( m_name > b.name() )
        return true;
    else
        return false;
}
*/

bool Node::operator<(const Node& b)const {
	if (this->dist < b.Dist())
		return true;
	else return false;
}
bool Node::operator>(const Node& b)const {
	if (this->dist > b.Dist())
		return true;
	else return false;
}
/*
const Node Node::operator=(const Node& b) {
	return b;
}*/