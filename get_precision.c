#include "main.h"

/**
 * precision_getter - This will calculate the precision argument before printing
 * @format: the clean string format to print
 * @i: all arguments to be outputed.
 * @list: all arguments to be outputed.
 *
 * Return: Precision value.
 */
int precision_getter(const char *format, int *i, va_list list)
{
	int now_i = *i + 1;
	int precision = -1;

	if (format[now_i] != '.')
		return (precision);

	precision = 0;

	for (now_i += 1; format[now_i] != '\0'; now_i++)
	{
		if (is_numeric(format[now_i]))
		{
			precision *= 10;
			precision += format[now_i] - '0';
		}
		else if (format[now_i] == '*')
		{
			now_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = now_i - 1;

	return (precision);
}
/*Group: Stephen Amponsah and Jonah Etuaful*/
