
#include "HeapPriorityQueue.h"
#include <iostream>
#include <algorithm>

using namespace std;


//template<typename T>
struct lesser {
	bool operator() (const Node& e1, const Node& e2)const {
		if (e1 > e2)return true;
		else return false;
	}
};

//template<typename T>
MinHeapQueue::MinHeapQueue() {
	QueueVec = vector<Node>();
	make_heap(QueueVec.begin(), QueueVec.end(), lesser());
}
//template<typename T>
MinHeapQueue::MinHeapQueue(Node& s, vector<Node>& ns ) {
	QueueVec = vector<Node>();
	s.setDist(0);
	QueueVec.push_back(s);
	for (vector<Node>::iterator itr = ns.begin(); itr != ns.end(); ++itr) {
		if(*itr != s )
			QueueVec.push_back(*itr);
	}
	make_heap(QueueVec.begin(), QueueVec.end(), lesser());
}

//template<typename T>
void MinHeapQueue::Insert(Node &t) {
	QueueVec.push_back(t);
	push_heap(QueueVec.begin(), QueueVec.end(), lesser());
}
//template<typename T>
void MinHeapQueue::RemoveMin() {
	QueueVec.erase(QueueVec.begin());
	pop_heap(QueueVec.begin(), QueueVec.end(),  lesser());
}

//template<typename T>
Node MinHeapQueue::Front()const{
	return QueueVec.front();
}

//template<typename T>
bool MinHeapQueue::isEmpty()const{
	return QueueVec.empty();
}

//template<typename T>
void MinHeapQueue::decreaseKey(Node& E, double dist) {
	Node temp;
	for (vector<Node>::iterator itr = QueueVec.begin(); itr != QueueVec.end(); ++itr) {
		if (*itr == E) {
			temp = *itr;
			temp.setDist(dist);
			QueueVec.erase(itr);
			QueueVec.push_back(temp);
			make_heap(QueueVec.begin(), QueueVec.end(), lesser());
			break;
		}
	}
}