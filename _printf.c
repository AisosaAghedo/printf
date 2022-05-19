/**
 * _printf - a function that mimics some of the functionality of the printf
 * @format: the format string
 * Return: 0
 */
int _printf(char *format, ...)
{
	va_list args;
	va_start(args, format);
	char *s, *r;
	char t[2];
	int i, count = 0, temp;
	unsigned int tmp;
	
	for (i = 0; i < strlen(format); i++)
	{
		if (format[i] == '%' || format[i - 1] == '%')
		{
			if (format[i + 1] == 's')
			{
				r = va_arg(args, char *);
				count = strlen(r) * sizeof(char);
				s = malloc(count + 1);
				strcpy(s, r);
				write(1, s, count);
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
					write(1, "-", 1);
					write(1, s, count);
					free(s);
				}
				else
				{
					r = int_to_str(temp);
					count = strlen(r) * sizeof(char);
					s = malloc(count + 1);
					strcpy(s, r);
					write(1, s, count);
					free(s);
				}
			}
			else if (format[i + 1] == 'c')
			{
				t[1] = va_arg(args, int);
				write(1, t, 2);
			}
			else if (format[i + 1] == 'u')
			{
				tmp = va_arg(args, unsigned int);
				r = int_to_str(tmp);
				count = strlen(r) * sizeof(char);
				s = malloc(count + 1);
				strcpy(s, r);
				write(1, s, count);
				free(s);
			}
		}
		else
		{
			t[1] = format[i];
			write(1,t,2);
		}
	}
	return (0);
}     
