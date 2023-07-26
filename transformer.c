#include "main.h"

/**
 * transform - transforms number and base into string
 * By Jonah and Stephen
 * @num: input number
 * @base: input base
 * @lowercase: if hexa values need to be lowercase, flag
 * Return: result string
 */
char *transform(unsigned long int num, int base, int lowercase)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}
