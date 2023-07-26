#include "main.h"
/**
 * handle_print - This will output an argument based on its type
 * @fmt: All formatted strings which are to be printed.
 * @list: the condition to be outputed.
 * @ind: index of the loop
 * @buffer: this is a buffer list to deal with print.
 * @flags: this will calculate the active available flags
 * @width: get the width.
 * @precision: get the precise identity
 * @size: Size specifier
 * Return: it will return 1 or 2;
 */
int print_handlert(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, chars_prntd = -1;
	fmt_t fmt_types[] = {
		{'c', char_printer}, {'s', str_printer}, {'%', pcnt_printer},
		{'i', print_int}, {'d', print_int}, {'b', bin_printer},
		{'u', uns_printer}, {'o', oct_printer}, {'x', hexd_printer},
		{'X', hex_up_printer}, {'p', pnt_printer}, {'S', not_printable_printer},
		{'r', reverse_printer}, {'R', rot13str_printer}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (chars_prntd);
}
/*Group: Stephen Amponsah and Jonah Etuaful*/
