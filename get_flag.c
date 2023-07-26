#include "main.h"

/**
 * get_flag - condition that turns on flags if _printf finds
 * a flag modifier in the format string
 * By Jonah and Stephen
 * @s: character that holds the flag specifier
 * @f: pointer to the struct flags in which the flags are turned on
 *
 * Return: 1 if a flag has been turned on, 0 otherwise
 */
int get_flag(char s, flags_t *f)
{
	int i = 0;

	switch (s)
	{
		case '+':
			f->str_plus = 1;
			i = 1;
			break;
		case ' ':
			f->str_space = 1;
			i = 1;
			break;
		case '#':
			f->str_hash = 1;
			i = 1;
			break;
	}

	return (i);
}
