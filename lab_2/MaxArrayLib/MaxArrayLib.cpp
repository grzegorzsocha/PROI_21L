#include <array>
#include "MaxArray.h"

bool check_condition(int number)
{
	int i=1, sum_odd=0, sum_even=0;
	while (number != 0)
	{
		if (i % 2 == 1)
			sum_odd += number % 10;
		else
			sum_even += number % 10;
		i++;
		number /= 10;
	}
	if (sum_odd == sum_even)
		return true;
	return false;
}

int max(std::array<std::array<int, maxColumns>, maxRows> array, size_t rows, size_t columns)
{
	int maximum = 0;
	for (size_t row = 0; row < rows; ++row)
		for (size_t column = 0; column < columns; ++column)
			if (check_condition(array[row][column]) && array[row][column] > maximum)
				maximum = array[row][column];
	return maximum;
}

