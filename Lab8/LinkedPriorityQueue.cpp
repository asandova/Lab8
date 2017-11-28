/**
*
*CS372: Lab8
*File: LinkedPrioityQueue.cpp
*Author: August B. Sandoval
*Purpose: the class definition of LinkedPrioityQueue.h
*
**/
#include <list>
#include "LinkedPriorityQueue.h"

using namespace std;

//template<typename T>
LinkedPQueue::LinkedPQueue() {
	PQueue = list<Node>();
}

//template<typename T>
LinkedPQueue::LinkedPQueue(Node &t) {
	PQueue = list<Node>();
	PQueue.push_back(t);
}

//template<typename T>
void LinkedPQueue::Insert(Node &n) {
	PQueue.push_back(n);
}

//template<typename T>
void LinkedPQueue::RemoveMin() {

	Node Ttemp = PQueue.back();
	PQueue.pop_front();
	PQueue.pop_back();
	PQueue.push_front(Ttemp);
	list<Node>::iterator n = PQueue.begin();
	siftDown(0, n );
}

//template<typename T>
Node LinkedPQueue::Front()const {
	return PQueue.front();
}

//template<typename T>
bool LinkedPQueue::isEmpty()const {
	return !PQueue.empty();
}

//need to revise
//template<typename T>
void LinkedPQueue::decreaseKey(Node& E, double dist) {
	Node temp;
	list<Node>::iterator n;
	for (n = PQueue.begin(); n != PQueue.end() ; ++n) {
		if (*n == E) {
			temp = *n;
			PQueue.erase(n);
			break;
		}
	}
	temp.setDist(dist);
	PQueue.push_back(temp);
	siftUp( PQueue.size() , n = PQueue.rbegin() );
}

//template<typename T>
void LinkedPQueue::siftDown(size_t I, list<Node>::iterator n) {
	size_t i;
	if (I * 2 <= PQueue.size() ) {
		list<Node>::iterator L = n;
		for ( i = I; i <= I * 2; ++L);
		if (*n > *L) {
			Node temp = *n;
			*n = *L;
			*L = temp;
		}
		siftDown(i, L);
	}
	if (I * 2 <= PQueue.size()) {
		list<Node>::iterator R = n;
		for (size_t i = I; i <= I * 2; ++R);
		if (*n > *R) {
			Node temp = *n;
			*n = *R;
			*R = temp;
		}
		siftDown(i, R);
	}

}

//template<typename T>
void LinkedPQueue::siftUp(size_t I, list<Node>::iterator n) {

	if (I == 0)
		return;
	else {
		size_t dif = I - (I / 2);
		typename list<Node>::iterator R;
		for (R = n; dif != 0; ++R , dif--);
		if (*n < *R) {
			Node temp = *n;
			*n = *R;
			*R = temp;
		}
		siftUp(I /2, R);
	}
}