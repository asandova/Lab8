#ifndef LINKEDPRIOITYQUEUE_H
#define LINKEDPRIOITYQUEUE_H

#include <list>

using namespace std;

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
	void siftDown(size_t I , typename list<T>::iterator n );
	void siftUp(  size_t I , typename list<T>::iterator n );
	typename list<T> PQueue;
};

#endif // !LINKEDPRIOITYQUEUE_H
