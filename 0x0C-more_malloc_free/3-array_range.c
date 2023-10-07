#include <stdlib.h>
#include "main.h"

/**
 * *array_range - creates an array of integers
 * @min: minimum range of values stored
 * @max: maximum range of values stored and number of elements
 *
 * Return: pointer to the new array
 */
int *array_range(int min, int max)
{
	int index;
	int *buffer;
	int range;

	if(min > max)
		return NULL;
	range = min - max;
	buffer = (malloc(range *sizeof(int)));
	if (!buffer)
		return NULL;
	index = 0;
	while(index < range)
	{
		buffer[index] = min + index;
		index++;
	}
	return(buffer);
}
