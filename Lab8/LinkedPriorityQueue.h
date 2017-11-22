#ifndef LINKEDPRIOITYQUEUE_H
#define LINKEDPRIOITYQUEUE_H


template<typename T>
struct Element {
	size_t index;
	T* pre;
	T cont;
	T* next;
};

template<typename T>
class LinkedPQueue
{
public:
	LinkedPQueue();
	LinkedPQueue(T &t);
	void Insert(T &t);
	void Remove();
	T& Front()const;
	bool isEmpty()const;
private:
	size_t Qsize;
	Element<T> *QHead;
	Element<T> *QTail;
	void decreaseKey();
};

#endif // !LINKEDPRIOITYQUEUE_H
