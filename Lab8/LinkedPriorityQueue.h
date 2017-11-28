#ifndef LINKEDPRIOITYQUEUE_H
#define LINKEDPRIOITYQUEUE_H

#include <list>
#include <vector>
#include "Node.h"
using namespace std;

//template<typename T>
class LinkedPQueue
{
public:
	LinkedPQueue();
	LinkedPQueue(Node& t, vector<Node>& ns);
	void Insert(Node& t);
	void RemoveMin();
	Node Front()const;
	bool isEmpty()const;
	void decreaseKey(Node& E, double dist);
private:
	void siftDown(size_t I , list<Node>::iterator n );
	void siftUp(  size_t I , list<Node>::reverse_iterator n );
	list<Node> PQueue;
};

#endif // !LINKEDPRIOITYQUEUE_H
