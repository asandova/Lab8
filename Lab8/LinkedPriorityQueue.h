#ifndef LINKEDPRIOITYQUEUE_H
#define LINKEDPRIOITYQUEUE_H

#include <list>
template<typename T>
class LinkedPQueue
{
public:
	LinkedPQueue();
	LinkedPQueue(T &t);
	void Insert(T &t);
	void RemoveMin();
	T& Front()const;
	bool isEmpty()const;
	void decreaseKey();
private:
	void siftDown(size_t I , list<T>::iterator n );
	void siftUp(  size_t I , list<T>::iterator n );
	list<T> PQueue;
};

#endif // !LINKEDPRIOITYQUEUE_H
