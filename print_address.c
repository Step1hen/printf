#include "main.h"

/**
 * print_addr - prints address of input in hexa format
 * By Jonah and Stephen
 * @l: gets va_list arguments from _printf
 * @f: gets the pointer to the struct flags that is being received
 * if a flag is passed to _printf
 * Return: number of char printed on output
 */
int print_addr(va_list l, flags_t *f)
{
	char *str;
	unsigned long int p = va_arg(l, unsigned long int);

	register int count = 0;

	(void)f;

	if (!p)
		return (_puts("(nil)"));
	str = transform(p, 16, 1);
	count += _puts("0x");
	count += _puts(str);
	return (count);
}
