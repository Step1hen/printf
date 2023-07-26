#include "main.h"

/**
 * print_int - prints an integer or whole number
 * By Jonah and Stephen
 * @l: va_list of arguments from _printf function
 * @f: pointer to the struct flags activation
 * if a flag is passed to _printf
 * Return: number of char's printed
 */
int print_int(va_list l, flags_t *f)
{
	int n = va_arg(l, int);
	int res = iterate_num(n);

	if (f->str_space == 1 && f->str_plus == 0 && n >= 0)
		res += _putchar(' ');
	if (f->str_plus == 1 && n >= 0)
		res += _putchar('+');
	if (n <= 0)
		res++;
	print_numb(n);
	return (res);
}

/**
 * print_unsnd - prints an unsigned integer/number
 * @l: va_list of arguments from _printf function
 * @f: pointer to the struct flags activation
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_unsnd(va_list l, flags_t *f)
{
	unsigned int u = va_arg(l, unsigned int);
	char *str = transform(u, 10, 0);

	(void)f;
	return (_puts(str));
}

/**
 * print_numb - helper function that loops through
 * an integer value and print all its numbers/digits one by one
 * @n: integer to be printed
 */
void print_numb(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n;
	}
	else
		n1 = n;

	if (n1 / 10)
		print_numb(n1 / 10);
	_putchar((n1 % 10) + '0');
}

/**
 * iterate_num - returns the number of individual digits
 * in an integer for _printf
 * @i: integer to evaluate
 * Return: number of single digits
 */
int iterate_num(int i)
{
	unsigned int d = 0;
	unsigned int u;

	if (i < 0)
		u = i * -1;
	else
		u = i;
	while (u != 0)
	{
		u /= 10;
		d++;
	}
	return (d);
}
