#include "Stack.h"

template <typename T, int N>
void Stack<T, N>::reverse()
{
	int size = Queue<T, N>::getQuantity();
	for (int i = 0, j = size - 1; i < j; i++, j--)
	{
		T temp = Queue<T, N>::tab[i];
		Queue<T, N>::tab[i] = Queue<T, N>::tab[j];
		Queue<T, N>::tab[j] = temp;
	}
}