
#include "HeapPriorityQueue.h"
#include <iostream>
#include <algorithm>

using namespace std;


//template<typename T>
struct lesser {
	bool operator() (const Node& e1, const Node& e2)const {
		if (e1 < e2)return true;
		else return false;
	}
};

//template<typename T>
MinHeapQueue::MinHeapQueue() {
	QueueVec = vector<Node>();
	make_heap(QueueVec.begin(), QueueVec.end(), lesser());
}
//template<typename T>
MinHeapQueue::MinHeapQueue(Node& t) {
	QueueVec = vector<Node>();
	QueueVec.push_back(t);
	make_heap(QueueVec.begin(), QueueVec.end(), lesser());
}

//template<typename T>
void MinHeapQueue::Insert(Node &t) {
	QueueVec.push_back(t);
	push_heap(QueueVec.begin(), QueueVec.end(), lesser());
}
//template<typename T>
void MinHeapQueue::RemoveMin() {
	QueueVec.pop_back();
	pop_heap(QueueVec.begin(), QueueVec.end(),  lesser());
}

//template<typename T>
Node MinHeapQueue::Front()const{
	return QueueVec.front();
}

//template<typename T>
bool MinHeapQueue::isEmpty()const{
	return !QueueVec.empty();
}

//template<typename T>
void MinHeapQueue::decreaseKey(Node& E, double dist) {
	
}