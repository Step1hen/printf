#include "main.h"

/**
 * get_print - chooses the right function that prints
 * depending on the conversion specifier passed to _printf
 * @s: a character that holds the conversion specifier
 * Description: the function loops through the structs array
 * func_arrays[] to find a match between the specifier passed to _printf
 * and the first element of the struct, and then the appropriate
 * printing function
 * Return: a pointer to the matching printing function
 */
int (*get_print(char s))(va_list, flags_t *)
{
	ph func_arrays[] = {
		{'i', print_int},
		{'s', print_strg},
		{'c', print_char},
		{'d', print_int},
		{'u', print_unsnd},
		{'x', print_hexa},
		{'X', print_hexa_upper},
		{'b', print_bin},
		{'o', print_oct},
		{'R', print_rot13},
		{'r', print_reverse},
		{'S', print_bigS},
		{'p', print_addr},
		{'%', print_pcnt}};
	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
		if (func_arrays[i].c == s)
			return (func_arrays[i].f);
	return (NULL);
}

