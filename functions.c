#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints all char values
 * @types: A full list a of all arguments types
 * @buffer: The buffer array to deal with print
 * @flags:  Calculates the active flags
 * @width: Complete width
 * @precision: Precision specification
 * @size: Size evaluator
 * Return: Number of chars to be echoed
 */
int char_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (char_setter(c, buffer, flags, width, precision, size));
}
/********* IS TO PRINTS A GIVEN STRING ********/
/**
 * @types: List a of arguments
 * @buffer: array of buffer to print
 * @flags:  active flags summed
 * @width: width getters.
 * @precision: Precision 
 * @size: Size specifier
 * Return: Number of chars printed
 */
int str_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & FLG_NEGATIVE)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/****** OUTPUT THE PERCENT SYMBOL ********/
/**
 * pcnt_printer - outputs the percent symber
 * @types: Listed the arguments
 * @buffer: Buffer array list to print
 * @flags:  sums the active flags
 * @width: width getter
 * @precision: Precision identification
 * @size: Size allocator
 * Return: Number of chars to be printed
 */
int pcnt_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/***** PRINT INTEGER VALUE (INT) ***********/
/**
 * print_int - print the integer values - int
 * @types: Listed arguments
 * @buffer: array list to deal with print
 * @flags:  Calculates the number of  flags
 * @width: get width.
 * @precision: Precision pointing
 * @size: Size allocator
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = MAX_BUFFER_SIZE - 2;
	int is_negative = 0;
	long int a = va_arg(types, long int);
	unsigned long int num;

	a = convert_size_number(a, size);

	if (a == 0)
		buffer[i--] = '0';

	buffer[MAX_BUFFER_SIZE - 1] = '\0';
	num = (unsigned long int)a;

	if (a < 0)
	{
		num = (unsigned long int)((-1) * a);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (num_setter(is_negative, i, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int a[32];
	unsigned int a, b, i, sum;
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	a = va_arg(types, unsigned int);
	b = 2147483648; /* (2 ^ 31) */
	a[0] = a / b;
	for (i = 1; i < 32; i++)
	{
		b /= 2;
		a[i] = (a / b) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char x = '0' + a[i];

			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
/*Group: Stephen Amponsah and Jonah Etuaful*/
