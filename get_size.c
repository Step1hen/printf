#include "main.h"

/**
 * size_getter - This will calculate the sizes to change the argument
 * @format: the clean string format to print
 * @i: index of all arguments.
 *
 * Return: Precision.
 */
int size_getter(const char *format, int *i)
{
	int now_i= *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = now_i- 1;
	else
		*i = curr_i;

	return (size);
}
/*Group: Stephen Amponsah and Jonah Etuaful*/
