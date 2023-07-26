#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: This is formatting function.
 * @fm_t: This is function associated variable for the function.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int print_handlert(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int char_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int str_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int pcnt_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int bin_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int uns_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int oct_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int hexd_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int hex_up_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int hexa_printer(va_list types, char compare_to[],
char buffer[], int flags, char flag_char, int width, int precision, int size);

/* Print a non printable characters */
int not_printable_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Print the specific memory address */
int pnt_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Handle other notable specifiers */
int flags_getter(const char *format, int *i);
int width_getter(const char *format, int *i, va_list list);
int precision_getter(const char *format, int *i, va_list list);
int size_getter(const char *format, int *i);

/*Print string in reverse format*/
int reverse_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Print a string in rot 13*/
int rot13str_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* This is width handler function */
int char_setter(char c, char buffer[],
	int flags, int width, int precision, int size);
int number_setter(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int num_setter(int ind, char bffs[], int flags, int width, int precision,
	int length, char prnt_add, char other_char);
int pnt_setter(char buffer[], int ind, int length,
	int width, int flags, char prnt_add, char other_char, int prnt_add_start);

int usnd_setter(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS FUNC needed in other files ******************/
int is_printable(char);
int add_hexa_code(char, char[], int);
int is_digit(char);

long int num_size_changer(long int num, int size);
long int usnd_size_changer(unsigned long int num, int size);

#endif /* MAIN_H */

