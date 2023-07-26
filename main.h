#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(y) (void)(y)
#define MAX_BUFFER_SIZE 1024

/* ALL SIZES */
#define SHT_SHORT 2
#define SHT_LONG 1

/* ALL FLAGS */
#define FLG_NEGATIVE 1
#define FLG_PLUS 2
#define FLG_ZERO 4
#define FLG_HASH 8
#define FLG_BLANK 16


/**
 * fmt struct - Operation for Struct
 *
 * @fmt: The format.
 * @fn: The affiliated funtion to fmt.
 */
struct fmt
{
	char fmt;
	int (*func)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Operation for Struct
 *
 * @fmt: The format.
 * @fm_t: The affiliated funtion to fmt.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int print_handler(const char *fmt, int *i,
	va_list list, char buffer[], int flags, int width, int accuracy, int size);

/********* ALL MISCELLAENOUS FUNCTIONS *********/

/* Print all numerals including binaries */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int uns_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int bin_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int oct_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int hex_up_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int hexd_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Print out char(c) and string literals (s) */
int pcnt_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int str_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int char_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int hexa_printer(va_list types, char map_to[],
char buffer[], int flags, char flag_char, int width, int precision, int size);

/* Print the exact memory addresses */
int pnt_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Print all non characters that cannot be printed */
int not_printable_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Print reversed string */
int reverse_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Print rot 13 strings or characters */
int rot13str_printer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Get other specifiers */
int width_getter(const char *format, int *i, va_list list);
int size_getter(const char *format, int *i);
int precision_getter(const char *format, int *i, va_list list);
int flags_getter(const char *format, int *i);

/* handle width setters */
int num_setter(int ind, char buff[], int flags, int width, int precision,
	int length, char p_add, char other_char);
int number_setter(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int char_setter(char c, char buffer[],
	int flags, int width, int precision, int size);
int pnt_setter(char buffer[], int ind, int length,
	int width, int flags, char p_add, char other_char, int start_p_add);
int usnd_setter(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size);

/******* UTILITY FILES - UTILS.C FILE *******/
/* validate converters */
int is_numeric(char);
int add_hexa_code(char, char[], int);
int is_printable(char);

/* handle size converters */
long int usnd_size_changer(unsigned long int num, int size);
long int num_size_changer(long int num, int size);

#endif /* END MAIN_H */
