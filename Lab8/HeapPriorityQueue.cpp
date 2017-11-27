
#include "HeapPriorityQueue.h"
#include <iostream>
#include <algorithm>

using namespace std;


template<typename T>
struct lesser {
	bool operator() (const T& e1, const T& e2)const {
		if (e1 < e2)return true;
		else return false;
	}
};

template<typename T>
MinHeapQueue::MinHeapQueue() {
	QueueVec = vector<T>();
	make_heap(QueueVec.begin(), QueueVec.end(), lesser());
}
template<typename T>
MinHeapQueue::MinHeapQueue(T& t) {
	QueueVec = vector<T>();
	QueueVec.push_back(t);
	make_heap(QueueVec.begin(), QueueVec.end(), lesser());
}

template<typename T>
void MinHeapQueue::Insert(T &t) {
	QueueVec.push_back(t);
	push_heap(QueueVec.begin(), QueueVec.end(), lesser());
}
template<typename T>
void MinHeapQueue::RemoveMin() {
	QueueVec.pop_back(t);
	pop_heap(QueueVec.begin(), QueueVec.end(), lesser());
}

template<typename T>
T& MinHeapQueue::Front()const{
	return QueueVec.front();
}

template<typename T>
bool MinHeapQueue::isEmpty()const{
	return !QueueVec.empty();
}

template<typename T>
void MinHeapQueue::decreaseKey() {
	
}