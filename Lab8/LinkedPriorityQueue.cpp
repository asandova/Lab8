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

template<typename T>
LinkedPQueue<T>::LinkedPQueue() {
	PQueue = list<T>();
}

template<typename T>
LinkedPQueue<T>::LinkedPQueue(T &t) {
	PQueue = list<T>();
	PQueue.push_back(t);
}

template<typename T>
void LinkedPQueue<T>::Insert(T &t) {
	PQueue.push_back(t);
}

template<typename T>
void LinkedPQueue<T>::RemoveMin() {

	T Ttemp = PQueue.back();
	PQueue.pop_front();
	PQueue.pop_back();
	PQueue.push_front(Ttemp);
	decreseKey();
}

template<typename T>
T& LinkedPQueue<T>::Front()const {
	return PQueue.front();
}

template<typename T>
bool LinkedPQueue<T>::isEmpty()const {
	return !PQueue.empty()
}

template<typename T>
void LinkedPQueue<T>::decreaseKey() {
	//size_t currentIndex = 1;
	siftDown(1, PQueue.begin() );
}

template<typename T>
void LinkedPQueue<T>::siftDown(size_t I, typename list<T>::iterator n) {

	if (I * 2 <= PQueue.size() ) {
		list<T>::interator L = n;
		for (size_t i = I; i <= I * 2; ++L);
		if (*n > *L) {
			T temp = *n;
			n* = *L;
			*L = temp;
		}
		siftDown(i, L);
	}
	if (I * 2 <= PQueue.size()) {
		list<T>::interator R = n;
		for (size_t i = I; i <= I * 2; ++R);
		if (*n > *L) {
			T temp = *n;
			n* = *L;
			*L = temp;
		}
		siftDown(i, R);
	}

}

template<typename T>
void LinkedPQueue<T>::siftUp(size_t I, typename list<T>::iterator n) {

	if (I == 0)
		return;
	else {
		size_t dif = I - (I / 2);
		list<T>::iterator R;
		for (R = n; dif != 0; ++R , dif--);
		if (*n < *R) {
			T temp = *n;
			*n = *R;
			*R = temp;
		}
		siftUp(I /2, R);
	}
}