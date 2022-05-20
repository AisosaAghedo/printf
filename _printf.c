#include "main.h"
/**
 * _printf - a function that mimics some of the functionality of the printf
 * @format: the format string
 * Return: 0
 */
int _printf(const char *format, ...)
{
	va_list args;
	char *s;
	char *r;
	char *u;
	char t[2];
	int count = 0, temp, i, total = 0;
	unsigned int tmp;
	
	va_start(args, format);
	for (i = 0; i < (int)strlen(format); i++)
	{
		if (format[i] == '%' || format[i - 1] == '%')
		{
			if (format[i + 1] == '%')
			{
				t[0] = '%';
				t[1] = '\0';
				strcpy(s, t);
				write(1, s, 1);
			}
			if (format[i + 1] == 's')
			{
				r = va_arg(args, char *);
				total += strlen(r);
				count = strlen(r) * sizeof(char);
				s = malloc(count + 1);
				strcpy(s, r);
				write(1, s, count + 1);
				free(s);
			}
			else if (format[i + 1] == 'i' || format[i + 1] == 'd')
			{
				temp = va_arg(args, int);
				if (temp < 0)
				{
					r = int_to_str(-1 *temp);
					count = strlen(r) * sizeof(char);
					s = malloc(count + 1);
					strcpy(s, r);
					total += strlen(r);
					write(1, "-", 1);
					write(1, s, count);
					free(s);
				}
				else
				{
					r = int_to_str(temp);
					count = strlen(r) * sizeof(char);
					s = malloc(count + 1);
					total += strlen(r);
					strcpy(s, r);
					write(1, s, count);
					free(s);
				}
			}
			else if (format[i + 1] == 'c')
			{
				t[0] = va_arg(args, int);
				t[1] = '\0';
				total += 1;
				write(1, t, 1);
			}
			else if (format[i + 1] == 'u')
			{
				tmp = va_arg(args, unsigned int);
				r = unsigned_to_str(tmp);
				count = strlen(r) * sizeof(char);
				u = malloc(count + 1);
				total += strlen(r);
				strcpy(u, r);
				write(1, u, count);
				free(u);
			}
		}
		else if (format[i] == '\n')
		{
			write(1, "\n", 1);
		}
		else
		{
			t[0] = format[i];
			t[1] = '\0';
			total += 1;
			write(1,t,1);
		}
	}
	return (total);
}     
