#include "main.h"

/**
 * width_getter - This will calculate the width to change the argument
 * @format: the clean string format to print
 * @i: index of all arguments.
 * @list: all arguments to be outputed.
 *
 * Return: the width.
 */
int width_getter(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	for (now_i= *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = now_i- 1;

	return (width);
}
/*Group: Stephen Amponsah and Jonah Etuaful*/
