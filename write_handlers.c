#include "main.h"

/******** HANDLE WRITING OF VALUE *********/
/**
 * char_setter - Prints a string value
 * @c: char types.
 * @buffer: Buffer list to print
 * @flags:  Gets all active flags.
 * @width: gets the absolute width.
 * @precision: gets the precision specifier
 * @size: get the size specifier
 *
 * Return: Number of chars printed.
 */
int char_setter(char c, char buffer[],
	int flags, int width, int precision, int size)
{ /* char is stored at left and paddind at buffer's right */
	int i = 0;
	char prnt_add = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & FLG_ZERO)
		prnt_add = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[MAX_BUFFER_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[MAX_BUFFER_SIZE - i - 2] = prnt_add;

		if (flags & FLG_NEGATIVE)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[MAX_BUFFER_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[MAX_BUFFER_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/********* WRITE WHOLE NUMBERS ***********/
/**
 * number_setter - Prints a number
 * @c: char types.
 * @buffer: Buffer list to print
 * @flags:  Gets all active flags.
 * @width: gets the absolute width.
 * @precision: gets the precision specifier
 * @size: get the size specifier
 *
 * Return: Number of chars printed.
 */
int number_setter(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = MAX_BUFFER_SIZE - ind - 1;
	char prnt_add = ' ', other_char = 0;

	UNUSED(size);

	if ((flags & FLG_ZERO) && !(flags & FLG_NEGATIVE))
		prnt_add = '0';
	if (is_negative)
		other_char = '-';
	else if (flags & F_PLUS)
		other_char = '+';
	else if (flags & F_SPACE)
		other_char = ' ';

	return (num_setter(ind, buffer, flags, width, precision,
		length, prnt_add, other_char));
}

/**
 * num_setter - sets a number using a bufffer
 * @ind: instance of index number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: length of number
 * @prnt_add: Add Pading char
 * @other_char: Extra char
 *
 * Return: Number of printed chars.
 */
int num_setter(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char prnt_add, char other_char)
{
	int i, start_p_add = 1;

	if (prec == 0 && ind == MAX_BUFFER_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == MAX_BUFFER_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = prnt_add = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		prnt_add = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (other_char != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = prnt_add;
		buffer[i] = '\0';
		if (flags & FLG_NEGATIVE && prnt_add == ' ')/* Asign extra char to left of buffer */
		{
			if (other_char)
				buffer[--ind] = other_char;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & FLG_NEGATIVE) && prnt_add == ' ')/* extra char to left of buff */
		{
			if (other_char)
				buffer[--ind] = other_char;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & FLG_NEGATIVE) && prnt_add == '0')/* extra char to left of prnt_add */
		{
			if (other_char)
				buffer[--start_p_add] = other_char;
			return (write(1, &buffer[start_p_add], i - start_p_add) +
				write(1, &buffer[ind], length - (1 - start_p_add)));
		}
	}
	if (other_char)
		buffer[--ind] = other_char;
	return (write(1, &buffer[ind], length));
}

/**
 * usnd_setter - Writes an unsigned number
 * @is_negative: Number indicating if the num is a negative value
 * @ind: instance of index number starts on the buffer
 * @buffer: Gets array list of chars
 * @flags: Gets Flags specifiers
 * @width: Gets Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of set/written chars.
 */
int usnd_setter(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	/* The number is stored at the buffer right and starts at the position i */
	int length = MAX_BUFFER_SIZE - ind - 1, i = 0;
	char prnt_add = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == MAX_BUFFER_SIZE - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0)  no additional char is printed */

	if (precision > 0 && precision < length)
		prnt_add = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & FLG_ZERO) && !(flags & FLG_NEGATIVE))
		prnt_add = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = prnt_add;

		buffer[i] = '\0';

		if (flags & FLG_NEGATIVE) /* Asign extra char to left of buffer [buffer>prnt_add]*/
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else /* Asign extra char to left of padding [prnt_add>buffer]*/
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * pnt_setter - Write a memory address
 * @buffer: Arrays of chars
 * @ind: instance of index number starts on the buffer
 * @buffer: Gets array list of chars
 * @flags: Gets Flags specifiers
 * @width: Gets Width specifier
 * @prnt_add: The particular char representing the padding
 * @other_char: The particular char representing extra char
 * @start_p_add: instance of index number at which padding should start
 *
 * Return: Number of set/written chars.
 */
int pnt_setter(char buffer[], int ind, int length,
	int width, int flags, char prnt_add, char other_char, int start_p_add)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = prnt_add;
		buffer[i] = '\0';
		if (flags & FLG_NEGATIVE && prnt_add == ' ')/* Asign extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (other_char)
				buffer[--ind] = other_char;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & FLG_NEGATIVE) && prnt_add == ' ')/* other char string to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (other_char)
				buffer[--ind] = other_char;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & FLG_NEGATIVE) && prnt_add == '0')/* other char to left of prnt_add */
		{
			if (other_char)
				buffer[--start_p_add] = other_char;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[start_p_add], i - start_p_add) +
				write(1, &buffer[ind], length - (1 - start_p_add) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (other_char)
		buffer[--ind] = other_char;
	return (write(1, &buffer[ind], MAX_BUFFER_SIZE - ind - 1));
}
/*Group: Stephen Amponsah and Jonah Etuaful*/
