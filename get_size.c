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
	int now_i = *i + 1;
	int size = 0;

	if (format[now_i] == 'l')
		size = SHT_LONG;
	else if (format[now_i] == 'h')
		size = SHT_SHORT;

	if (size == 0)
		*i = now_i - 1;
	else
		*i = now_i;

	return (size);
}
/*Group: Stephen Amponsah and Jonah Etuaful*/

