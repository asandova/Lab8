/**
*
*CS372: Lab8
*File: LinkedPrioityQueue.cpp
*Author: August B. Sandoval
*Purpose: the class definition of LinkedPrioityQueue.h
*
**/

#include "LinkedPriorityQueue.h"

template<typename T>
LinkedPQueue<T>::LinkedPQueue() {
	QHead = nullptr;
	QTail = nullptr;
}

template<typename T>
LinkedPQueue<T>::LinkedPQueue(T &t) {
	QHead = &t;
	QTail = &t;
}

template<typename T>
void LinkedPQueue<T>::Insert(T &t) {
	Qsize++;
	Element<T> E;
	E.cont = t;
	E.index = Qsize;
	E.pre = QTail;
	E.next = nullptr;
	QTail = &E;
	//bubble up element

}

template<typename T>
void LinkedPQueue<T>::Remove() {
	QTail.next = QHead.next;
	QTail.pre = nullptr;
	QHead.next = nullptr;
	//decreseKey
}

template<typename T>
T& LinkedPQueue<T>::Front()const {
	return QHead->cont;
}

template<typename T>
bool LinkedPQueue<T>::isEmpty()const {
	if (Qsize != 0)
		return true;
	else
		return false;
}

template<typename T>
void LinkedPQueue<T>::decreaseKey() {

}