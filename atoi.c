#include "monty.h"
/**
 * _atoi - entry point
 * @s: pointer string
 * Return: int
 */
int _atoi(char *s)
{
	int len, i = 0, new, mult = 1, fact = 10, res = 0;

	if (s == NULL)
		return (-1);
	for (len = 0; s[len] != '\0'; len++)
		;
	if (s[0] == '-')
	{
		if (s[1] == '\0')
			return (-1);
		mult *= -1;
		i++;
	}
	while (i < len)
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);

		res = res * fact;
		new = s[i] - 48;
		res += new;
		i++;
	}
	res *= mult;
	return (res);
}
