#ifndef HEAPPRIORITYQUEUE_H
#define HEAPPRIORITYQUEUE_H

#include <vector>

template<typename T>
class MinHeapQueue
{
public:
	MinHeapQueue();
	MinHeapQueue(T& t);
	void Insert(T &t);
	void RemoveMin();
	T& Front()const;
	bool isEmpty()const;
	void decreaseKey();
private:
	vector<T> QueueVec;
};
#endif // !HEAPPRIORITYQUEUE_H

