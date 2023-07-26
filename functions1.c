#include "main.h"

/***** PRINT UNSIGNED VALUES *****/
/**
 * uns_printer - This will print a unsigned value
 * @types: List a of arguments
 * @buffer: Buffer list to print
 * @flags:  Gets all active flags.
 * @width: gets the absolute width.
 * @precision: gets the precision specifier
 * @size: get the size specifier
 * Return: Number of chars printed.
 */
int uns_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = MAX_BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = usnd_size_changer(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[MAX_BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (usnd_setter(0, i, buffer, flags, width, precision, size));
}

/****** PRINT UNSIGNED NUMBER IN OCTAL CODE  ********/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = MAX_BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = usnd_size_changer(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[MAX_BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & FLG_HASHN && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (usnd_setter(0, i, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL CODE **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (hexa_printer(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL CODE **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (hexa_printer(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER CODE **************/
/**
 * hexa_printer - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @compare_to: Array of values to map the number to
 * @buffer: Buffer list to print
 * @flags:  Gets all active flags.
 * @width: gets the absolute width.
 * @precision: gets the precision specifier
 * @size: get the size specifier
 * Return: Number of chars printed
 */
int hexa_printer(va_list types, char compare_to[], char buffer[],
	int flags, char flag_char, int width, int precision, int size)
{
	int i = MAX_BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = usnd_size_changer(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[MAX_BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = compare_to[num % 16];
		num /= 16;
	}

	if (flags & FLG_HASHN && init_num != 0)
	{
		buffer[i--] = flag_char;
		buffer[i--] = '0';
	}

	i++;

	return (usnd_setter(0, i, buffer, flags, width, precision, size));
}
/*Group: Stephen Amponsah and Jonah Etuaful*/
