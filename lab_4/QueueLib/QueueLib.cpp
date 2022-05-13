#include "QueueLib.h"
#include <stdexcept>


template <typename T, int N>
int Queue<T, N>::getQuantity()
{
	return quantity;
}

template <typename T, int N>
int Queue<T, N>::getCapacity()
{
	return capacity;
}

template <typename T, int N>
const T* Queue<T, N>::getTab()
{
	return tab;
}

template <typename T, int N>
void Queue<T, N>::addBegin(T element)
{
	if (quantity < capacity)
	{
		for (int i = quantity; i > 0; i--)
			tab[i] = tab[i - 1];
		tab[0] = element;
		quantity++;
	}
}

template <typename T, int N>
void Queue<T, N>::addEnd(T element)
{
	if (quantity < capacity)
	{
		tab[quantity] = element;
		quantity++;
	}
}

template <typename T, int N>
void Queue<T, N>::deleteBegin()
{
	if (quantity > 0)
	{
		for (int i = 0; i < quantity - 1; i++)
			tab[i] = tab[i + 1];
		quantity--;
	}
}

template <typename T, int N>
void Queue<T, N>::deleteEnd()
{
	if (quantity > 0)
		quantity--;
}

template <typename T, int N>
T Queue<T, N>::getBegin()
{
	if (quantity > 0)
		return tab[0];
	else
		throw std::invalid_argument("empty queue");
}

template <typename T, int N>
T Queue<T, N>::getEnd()
{
	if (quantity > 0)
		return tab[quantity - 1];
	else
		throw std::invalid_argument("empty queue");
}

template <typename T, int N>
void Queue<T, N>::clear()
{
	quantity = 0;
}
