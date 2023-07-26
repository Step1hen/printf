#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the char c to stdout function
 * By Jonah and Stephen
 * @c: Is the character to be printed out
 * Return: When true return 1.
 * On error, return -1 , and errno is set very well.
 * Description: _putchar uses a local buffer of 1024 to call write
 * as little as possible
 */
int _putchar(char c)
{
	static char buf[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buf, i);
		i = 0;
	}
	if (c != -1)
	{
		buf[i] = c;
		i++;
	}
	return (1);
}

/**
 * _puts - prints a string to stdout function
 * @str: pointer to the string to print
 * Return: number of chars written in string
 */
int _puts(char *str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}
