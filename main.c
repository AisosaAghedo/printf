#include "main.h"

int main(void)
{
	int i, j;
	i = _printf("s\n", "hello");
	j = printf("hello\n");
	printf("%d\n", i);
	printf("%d", j);
	return (0);
}
