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
#include <math.h>
using namespace std;

//template<typename T>
LinkedPQueue::LinkedPQueue() {
	PQueue = list<Node>();
}

//template<typename T>
LinkedPQueue::LinkedPQueue(Node &s, vector<Node>& ns) {
	PQueue = list<Node>();
	s.setDist(0);
	PQueue.push_back(s);
	for (vector<Node>::iterator itr = ns.begin(); itr != ns.end(); ++itr) {
		if (*itr != s)
			PQueue.push_back(*itr);
	}
}

//template<typename T>
void LinkedPQueue::Insert(Node &n) {
	PQueue.push_back(n);
}

//template<typename T>
void LinkedPQueue::RemoveMin() {

	PQueue.pop_front();//removing first element
	if (PQueue.size() > 1) {
		Node Ttemp = PQueue.back();//getting last element
		if(PQueue.size() > 0)
			PQueue.pop_back();//removeing last element
		PQueue.push_front(Ttemp);//pushing temp in front
		siftDown(1, PQueue.begin());
	}
}

//template<typename T>
Node LinkedPQueue::Front()const {
	return PQueue.front();
}

//template<typename T>
bool LinkedPQueue::isEmpty()const {
	return PQueue.empty();
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
	//list<Node>::reverse_iterator r;
	siftUp( PQueue.size() , PQueue.rbegin() );
}

//template<typename T>
void LinkedPQueue::siftDown(size_t I, list<Node>::iterator n) {
	size_t i;
	if (I >= PQueue.size()) {
		return;
	}
	if (I * 2 < PQueue.size() ) {
		list<Node>::iterator L;
		L = n;
		for ( i = I; i < I * 2; ++L , i++);
		if (*n > *L) {
			Node temp = *n;
			*n = *L;
			*L = temp;
		}
		siftDown(i, L);
	}
	if (I * 2 + 1 < PQueue.size()) {
		list<Node>::iterator R = n;
		for (i = I; i < I * 2 + 1; ++R ,i++);
		if (*n > *R) {
			Node temp = *n;
			*n = *R;
			*R = temp;
		}
		siftDown(i, R);
	}

}

//template<typename T>
void LinkedPQueue::siftUp(size_t I, list<Node>::reverse_iterator n) {

	size_t half = (int)I / 2;
	if ( half == 0 )
		return;
	else {

		size_t dif = (size_t)floor(I - half ) ;
		list<Node>::reverse_iterator R;
		for (R = n; dif != 0; ++R , dif--);
		if (*n < *R) {
			Node temp = *n;
			*n = *R;
			*R = temp;
		}
		siftUp((int)I /2, R);
	}
}