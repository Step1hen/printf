#include "main.h"

/***** PRINT POINTERS *******/
/**
 * pnt_printer - Prints the value of a pointer variable
 * @types: List a of all arguments
 * @buffer: Buffer list to print
 * @flags:  Gets all active flags.
 * @width: gets the absolute width.
 * @precision: gets the precision specifier
 * @size: get the size specifier
 * Return: Number of chars printed.
 */
int pnt_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char other_char = 0, prnt_add = ' ';
	int ind = MAX_BUFFER_SIZE - 2, length = 2, start_p_add = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char compare_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[MAX_BUFFER_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = compare_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & FLG_ZERO) && !(flags & FLG_NEGATIVE))
		prnt_add = '0';
	if (flags & FLG_PLUS)
		other_char = '+', length++;
	else if (flags & FLG_BLANK)
		other_char = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], MAX_BUFFER_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, prnt_add, other_char, start_p_add));
}

/********* PRINT NON PRINTABLE ************/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: List a of all arguments
 * @buffer: Buffer list to print
 * @flags:  Gets all active flags.
 * @width: gets the absolute width.
 * @precision: gets the precision specifier
 * @size: get the size specifier
 * Return: Number of chars printed
 */
int not_printable_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += add_hexa_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/******* PRINT REVERSE VALUE **********/
/**
 * reverse_printer - Prints reverse string.
 * @types: List a of all arguments
 * @buffer: Buffer list to print
 * @flags:  Gets all active flags.
 * @width: gets the absolute width.
 * @precision: gets the precision specifier
 * @size: get the size specifier
 * Return: Numbers of chars printed
 */

int reverse_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/******** PRINT A STRING IN ROT13 *******/
/**
 * rot13str_printer - Print a string in rot13.
 * @types: List of all arguments
 * @buffer: Buffer list to print
 * @flags:  Gets all active flags.
 * @width: gets the absolute width.
 * @precision: gets the precision specifier
 * @size: get the size specifier
 * Return: Numbers of chars printed
 */
int rot13str_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, k;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (k = 0; in[k]; k++)
		{
			if (in[k] == str[i])
			{
				x = out[k];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[k])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
/*Group: Stephen Amponsah and Jonah Etuaful*/
