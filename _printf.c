#include "main.h"
/**
 * _printf - a function that mimics some of the functionality of the printf
 * @format: the format string
 * Return: 0
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, bit;
	char *s;
	char *r;
	char t[2];
	int length = strlen(format), temp;
	va_start(args, format);

	for(i = 0; i < length; i++)
	{
		if (format[i] == '%' || format[i - 1] == '%')
		{
			if (format[i] == 'i' || format[i] == 'd')
			{
				temp = va_arg(args, int);
				r = int_to_str(temp);
				bit = strlen(r) * sizeof(char);
				s = malloc(bit + sizeof(char));
				strcpy(s, r);
				write(1, s, bit + 1);
				free(s);
			}
			else if (format[i] == 's')
			{
				r = va_arg(args, char *);
				bit = strlen(r) * sizeof(char);
				s = malloc(bit + sizeof(char));
				strcpy(s, r);
				write(1, s, bit + sizeof(char));
				free(s);
			}
			else if (format[i] == 'c')
			{
				t[0] = va_arg(args, int);
				t[1] = '\0';
				bit = strlen(t) * sizeof(char);
				s = malloc(bit + sizeof(char));
				strcpy(s, t);
				write(1, s, bit + 1);
				free(s);
			}
			else if (format[i] == '[' || format[i] == ']' || format[i + 1] == '%')
			{
				t[0] = format[i];
				t[1] = '\0';
				write(1, t, 2);
			}
                }
		else
		{
			t[0] = format[i];
			t[1] = '\0';
			write(1, t, 2);
		}
	}
}
