#pragma once
#include "../QueueLib/QueueLib.h"

template <typename T, int N = 10>
class Stack : public Queue<T, N>
{
private:
	using Queue<T, N>::getBegin;
	using Queue<T, N>::addBegin;
	using Queue<T, N>::deleteBegin;
public:
	void reverse();
};