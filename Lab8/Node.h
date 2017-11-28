/**
*
*CS372: Lab4, Lab5, Lab6
*File: Node.h
*Author: August B. Sandoval
*Purpose: Provides the class definition for class Node
*
**/
#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

class Node {

private:
    string m_name;
    int m_id;
	double dist;
	int preID;
	double Latitude;
	double Longitude;

public:
        Node();
        Node(const string & name, int id);
		Node(const string & name, int id, double lat, double l);
		const static Node NULL_NODE;
        friend ostream& operator<<(ostream & out, const Node & n);
        bool operator==(const Node & b)const;
        bool operator!=(const Node & b)const;
		bool operator>(const Node & b)const;
        bool operator<(const Node & b)const;
		//const Node operator=(const Node& b);

        int id()const;
        void setID(int id);

		void setDist(double d);
		double Dist()const;

		void setPreID(int id);
		int PreID()const;

		void setLat(double lat);
		double Lat()const;

		void setLong(double l);
		double Long()const;

		const string & name()const;
};
#endif // NODE_H
