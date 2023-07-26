#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

/**
 * struct flags - there are struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @str_plus: flag for the add '+' character
 * @str_space: flag for the space or empty ' ' character
 * @str_hash: flag for the hash or pound sign'#' character
 */
typedef struct flags
{
	int str_plus;
	int str_space;
	int str_hash;
} flags_t;

/**
 * struct handle_print - struct to select the correct func depending
 * on the format specifier passed to _printf() function
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct handle_print
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} ph;

/* print numbers and digits */
int print_int(va_list l, flags_t *f);
void print_numb(int n);
int print_unsnd(va_list l, flags_t *f);
int iterate_num(int i);

/* print the number bases */
int print_hexa(va_list l, flags_t *f);
int print_hexa_upper(va_list l, flags_t *f);
int print_bin(va_list l, flags_t *f);
int print_oct(va_list l, flags_t *f);

/* transformer */
char *transform(unsigned long int num, int base, int lowercase);

/* _printf func declared */
int _printf(const char *format, ...);

/* get printed chars */
int (*get_print(char s))(va_list, flags_t *);

/* get_flag */
int get_flag(char s, flags_t *f);

/* print_alpha */
int print_strg(va_list l, flags_t *f);
int print_char(va_list l, flags_t *f);

/* write or set functions */
int _putchar(char c);
int _puts(char *str);

/* custom print functions */
int print_rot13(va_list l, flags_t *f);
int print_reverse(va_list l, flags_t *f);
int print_bigS(va_list l, flags_t *f);

/* print_addr */
int print_addr(va_list l, flags_t *f);

/* print the percent % symbol */
int print_pcnt(va_list l, flags_t *f);

#endif
