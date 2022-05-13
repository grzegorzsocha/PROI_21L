#pragma once

template <typename T, int N=10>
class Queue
{
private:
	const int capacity = N;
	int quantity = 0;
protected:
	T tab[N];
public:
	int getQuantity();
	int getCapacity();
	const T* getTab();
	T getBegin();
	T getEnd();

	void addBegin(T element);
	void addEnd(T element);

	void deleteBegin();
	void deleteEnd();

	void clear();
};