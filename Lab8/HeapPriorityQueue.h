#ifndef HEAPPRIORITYQUEUE_H
#define HEAPPRIORITYQUEUE_H

#include <vector>
#include "Node.h"
using namespace std;

//template<typename T>
class MinHeapQueue
{
public:
	MinHeapQueue();
	MinHeapQueue( Node & t);
	void Insert(Node &t);
	void RemoveMin();
	Node Front()const;
	bool isEmpty()const;
	void decreaseKey(Node& E, double dist);
private:
	vector<Node> QueueVec;
};
#endif // !HEAPPRIORITYQUEUE_H

