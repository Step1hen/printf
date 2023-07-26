#include "main.h"

/**
 * is_printable - This function checks if a char can be printed
 * @c: Char to be worked on.
 * Return: 1 if c is printable, and return 0 if its false
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * add_hexa_code - Append the ASCCI in hexadecimal format to the buffer
 * @buffer: list of chars.
 * @i: The instance at which to start add.
 * @ascii_rep: ASCCI code.
 * Return: This will always return 3 if its true
 */
int add_hexa_code(char ascii_rep, char buffer[], int i)
{
	char compare_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_rep < 0)
		ascii_rep *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = compare_to[ascii_rep / 16];
	buffer[i] = compare_to[ascii_rep % 16];

	return (3);
}

/**
 * is_numeric - Verifies if a char is a digit or not
 * @c: C refers to the char to be worked on
 *
 * Return: This will return 1 if c is a number, else returns 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * num_size_changer - Changes a num to the wanted size
 * @num: The number to be changed.
 * @size: The number showing the data type to be changed.
 *
 * Return: Changed value of num
 */
long int num_size_changer(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * usnd_size_changer - will change a num to the wanted size
 * @num: The number to be changed or altered
 * @size: The number indicating the data type to be changed
 *
 * Return: this will modify value of num
 */
long int usnd_size_changer(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
/*Group: Stephen Amponsah and Jonah Etuaful*/
