#include "main.h"
/**
 * _putchar - function to print a character
 * @c: character to be printed
 */
int _putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
int _puts(char *s)
{
	int i, size = strlen(s);

	for (i = 0; i <=size; i++)
	{
		_putchar(s[i]);
	}
	return (size);
}
