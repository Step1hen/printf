#include "main.h"

void buff_printer(char buffer[], int *single_buff);

/**
 * _printf - This is Printf function
 * @format: format file
 * Return: Printed characters or chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, chars_prntd = 0;
	int flags, width, precision, size, single_buff = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[single_buff++] = format[i];
			if (single_buff == BUFF_SIZE)
				buff_printer(buffer, &single_buff);
			/* write(1, &format[i], 1);*/
			chars_prntd++;
		}
		else
		{
			buff_printer(buffer, &single_buff);
			flags = flags_getter(format, &i);
			width = width_getter(format, &i, list);
			precision = precision_getter(format, &i, list);
			size = size_getter(format, &i);
			++i;
			printed = print_handlert(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			chars_prntd += printed;
		}
	}

	buff_printer(buffer, &single_buff);

	va_end(list);

	return (chars_prntd);
}

/**
 * buff_printer - Prints every details of the buffer if the program dies
 * @buffer: Array of chars
 * @single_buff: Object/array key (index) at which to add next char, this represents the length.
 */
void buff_printer(char buffer[], int *single_buff)
{
	if (*single_buff > 0)
		write(1, &buffer[0], *single_buff);

	*single_buff = 0;
}
/*Group: Stephen Amponsah and Jonah Etuaful*/

