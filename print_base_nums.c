#include "main.h"

/**
 * print_hexa - prints a number in hexadecimal base,
 * in lowercase
 * By Jonah and Stephen
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Description: this function calls transform() which then transforms the input
 * number into the correct base and returns it as a string
 * Return: the number of char printed
 */
int print_hexa(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = transform(num, 16, 1);
	int count = 0;

	if (f->str_hash == 1 && str[0] != '0')
		count += _puts("0x");
	count += _puts(str);
	return (count);
}

/**
 * print_hexa_upper - prints a number in hexadecimal base,
 * in uppercase
 * @l: va_list arguments from _printf
 * @f: pointer to the struct that determines
 * if a flag is passed to _printf
 * Description: this function calls transform() which then transforms the input
 * number into the correct base and returns it as a string
 * Return: the number of char printed
 */
int print_hexa_upper(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = transform(num, 16, 0);
	int count = 0;

	if (f->str_hash == 1 && str[0] != '0')
		count += _puts("0X");
	count += _puts(str);
	return (count);
}

/**
 * print_bin - prints a number in base 2
 * @l: va_list arguments from _printf
 * @f: pointer to the struct that determines
 * if a flag is passed to _printf
 * Description: the function calls transform() which then transforms the input
 * number into the correct base and returns it as a string
 * Return: the number of char printed
 */
int print_bin(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = transform(num, 2, 0);

	(void)f;
	return (_puts(str));
}

/**
 * print_oct - prints a number in base 8
 * @l: va_list arguments from _printf
 * @f: pointer to the struct that determines
 * if a flag is passed to _printf
 * Description: the function calls transform() which then transforms the input
 * number into the correct base and returns it as a string
 * Return: the number of char printed
 */
int print_oct(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = transform(num, 8, 0);
	int count = 0;

	if (f->str_hash == 1 && str[0] != '0')
		count += _putchar('0');
	count += _puts(str);
	return (count);
}
