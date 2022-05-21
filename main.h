#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
int _puts(char *s);
int _putchar(char c);
char STR[40];
int _printf(const char *format, ...);
char *int_to_str(int n);
char *unsigned_to_str(unsigned int n);
#endif
