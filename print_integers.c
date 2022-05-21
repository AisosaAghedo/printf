#include "main.h"

/**
 * print_i - prints an integer
 * @i: integer to be printed
 *
 * Return: number of chars and digits printed
 */
int print_i(va_list i)
{
	int a[10];
	int x, y, z, sum, counter;

	z = va_arg(i, int);
	counter = 0;
	y = 1000000000;
	a[0] = z / y;
	for (x = 1; x < 10; x++)
	{
		y /= 10;
		a[x] = (n / y) % 10;
	}
	if (z < 0)
	{
		_putchar('-');
		counter++;
		for (x = 0; x < 10; x++)
			a[x] *= -1;
	}
	for (x = 0, sum = 0; x < 10; x++)
	{
		sum += a[x];
		if (sum != 0 || x == 9)
		{
			_putchar('0' + a[x]);
			counter++;
		}
	}
	return (counter);
}

/**
 * print_d - prints a decimal
 * @d: decimal to print
 *
 * Return: number of characters and digits printed
 */
int print_d(va_list d)
{
	int a[10];
	int x, y, z, sum, counter;

	z = va_arg(d, int);
	counter = 0;
	y = 1000000000;
	a[0] = z / y;
	for (x = 1; x < 10; x++)
	{
		y /= 10;
		a[x] = (z / y) % 10;
	}
	if (z < 0)
	{
		_putchar('-');
		counter++;
		for (x = 0; x < 10; x++)
			a[x] *= -1;
	}
	for (x = 0, sum = 0; x < 10; x++)
	{
		sum += a[x];
		if (sum != 0 || x == 9)
		{
			_putchar('0' + a[x]);
			counter++;
		}
	}
	return (counter);
}
