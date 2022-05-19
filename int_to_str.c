#include "main.h"
/**
 * int_to_str - function to convert integers to strings
 * @n: integer to be converted
 * Return: integer in string form
 */
char *int_to_str(int n)
{
	int length;
	char s[40];
	int temp = 0, i = 0, j = 0;

	while (n != 0)
	{
		temp = n % 10;
		temp += '0';
		s[i] = temp;
		n /= 10;
		i++;
	}
	s[i] = '\0';
	length = strlen(s) - 1;
	for (i = length; i >= 0; i--)
	{
		STR[j] = s[i];
		j++;
	}
	return (STR);
}
