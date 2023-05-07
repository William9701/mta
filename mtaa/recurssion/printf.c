#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);

int main()
{
	int i = 255;
	char *y = "a beautiful";
	char *u = "hello";
	int count =_printf("Let's try to printf %x\n", i);
	printf("count is %d\n", count);
	return 0;
}

int _printf(const char *format, ...)
{

	int val;
	int remain;
	int hex[100];
	int b;
	int bin[32];
	int a = 0;
	int j;
	int u;
	int count;
	char c;
	int o;
	int d, i;
	char *s;
	va_list list;

	va_start(list, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
			{
				c = va_arg(list, int);
				putchar(c);
				count++;
			}
			else if (*format == 'u')
			{
				u = va_arg(list, int);
				while (u >= 0)
				{
					putchar(d + '0');
					count++;
				}
			}
			
			else if (*format == 'X')
			{
				val = va_arg(list, int);
				while (val != 0)
				{
					remain = val % 16;
					if (remain < 10)
					{
						hex[a] = 48 + remain;
					}
					else
					{
						hex[a] = 55 + remain;
					}
					a++;
					val = val / 16;
				}
				for (j = a-1; j >= 0; j--)
				{
					putchar(hex[j]);
					count++;
				}
			}

			else if (*format == 'x')
			{
				val = va_arg(list, int);
				while (val != 0)
				{
					remain = val % 16;
					if (remain < 10)
					{
						hex[a] = 48 + remain;
					}
					else
					{
						hex[a] = 87 + remain;
					}
					a++;
					val = val / 16;
				}
				for (j = a-1; j >= 0; j--)
				{
					putchar(hex[j]);
					count++;
				}
			}

			else if (*format == 'b')
			{
				b = va_arg(list, int);
				while (b > 0)
				{
					bin[a++] = b % 2;
					b /= 2;
				}
				for (j = a - 1; j >= 0; j--)
					putchar(bin[j] + '0');
			}
			else if (*format == 'o')
			{
				o = va_arg(list, int);
				while (o > 0)
				{
					bin[a++] = o % 8;
					o /= 8;
				}
				for (j = a - 1; j >= 0; j--)
					putchar (bin[j] + '0');
			}
			else if (*format == 's')
			{
				s= va_arg(list, char*);
				while (*s != '\0')
				{
				putchar(*s);
				s++;
				count++;
				}
			}
			else if (*format == 'd')
			{
				d = va_arg(list, int);
				putchar(d + '0');
				count++;
			}
			else if (*format == 'i')
			{
				i = va_arg(list, int);
				putchar(i +'0');
				count++;
			}
			else if (*format == '%')
			{
				putchar('%');
			}
		}
			else
			{
			putchar(*format);
			count++;
			}
		format++;
	}

	va_end(list);
	return count;
}

