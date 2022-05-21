#include "main.h"
/**
 * _printf - a function that mimics some of the functionality of the printf
 * @format: the format string
 * Return: 0
 */
int _printf(const char *format, ...)
{
	va_list args;
<<<<<<< HEAD
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
=======
	int i, bit;
	char *s;
	char *r;
	char t[2];
	int length = strlen(format), temp, total = 0;
	va_start(args, format);

	for(i = 0; i < length; i++)
	{
			if (format[i] == 'i' || format[i] == 'd')
			{
				temp = va_arg(args, int);
				r = int_to_str(temp);
				bit = strlen(r) * sizeof(char);
				s = malloc(bit + sizeof(char));
				strcpy(s, r);
				total += strlen(r);
				write(1, s, bit + 1);
				free(s);
			}
			else if (format[i] == 's')
			{
				r = va_arg(args, char *);
				bit = strlen(r) * sizeof(char);
				s = malloc(bit + sizeof(char));
				strcpy(s, r);
				total += strlen(r);
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
				total += 1;
				write(1, s, bit + 1);
				free(s);
			}
			else if (format[i] == '[' || format[i] == ']' || format[i + 1] == '%')
			{
				t[0] = format[i];
				t[1] = '\0';
				total += 1;
				write(1, t, 2);
			}
			else
			{
				t[0] = format[i];
				t[1] = '\0';
				total += 1;
				write(1, t, 2);
			}
	}
	return (total);
}
>>>>>>> b4e7b6862deb2222bd02c2e8656c0bfabe423d12
