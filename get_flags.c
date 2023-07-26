#include "main.h"

/**
 * flags_getter - This will calculate the active flags
 * @format: the clean string format to print
 * @i: take a parameter.
 * Return: Flags:
 */
int flags_getter(const char *format, int *i)
{
	int k, now_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {FLG_NEGATIVE, FLG_PLUS, FLG_ZERO, FLG_HASHN, FLG_BLANK, 0};

	for (now_i = *i + 1; format[now_i] != '\0'; now_i++)
	{
		for (k = 0; FLAGS_CH[k] != '\0'; k++)
			if (format[now_i] == FLAGS_CH[k])
			{
				flags |= FLAGS_ARR[k];
				break;
			}

		if (FLAGS_CH[k] == 0)
			break;
	}

	*i = now_i - 1;

	return (flags);
}
/*Group: Stephen Amponsah and Jonah Etuaful*/

