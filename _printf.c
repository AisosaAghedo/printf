#include "main.h"
/**
 * _printf - a function that mimics some of the functionality of the printf
 * @format: the format string
 * Return: 0
 */
int _printf(char *format, ...)
{
	va_list args;
	char c;
	char *str;
	int i, length = strlen(format), count = 0;
	va_start(args, format);

	for (i = 0; i < length; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(args, int);
				count += _putchar(c);
				continue;
			}
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				count += _puts(str);
				continue;
			}
			else
			{
				count += _putchar(format[i]);
				continue;
			}
		}
		else
		{
			if (format[i] != '\n')
			count += _putchar(format[i]);
			else
			{
				_putchar(format[i]);
			}
			
		}
	}
		va_end(args);

	return (0);
}     
