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

public:
        Node();
        Node(const string & name, int id);

		const static Node NULL_NODE;
        friend ostream& operator<<(ostream & out, const Node & n);
        bool operator==(const Node & b)const;
        bool operator!=(const Node & b)const;
        bool operator>(const Node & b)const;
        bool operator<(const Node & b)const;


        int id()const;
        void setID(int id);
		void setDist(double d);
		double Dist()const;
		void setPrev(Node & p);
        const string & name()const;
};
#endif // NODE_H
