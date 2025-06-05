#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return 1;
}

int ft_putstr(char *str)
{
	int count = 0;
	if(str == NULL)
		return(ft_putstr("(null)"));
	while(*str)
		count += ft_putchar(*str++);
	return count;
}

int ft_putnbr(int nb)
{
	long num = nb;
	int count = 0;

	if(num < 0)
	{
		count += ft_putchar('-');
		num = -num;
	}
	if(num >= 10)
		count += ft_putnbr(num / 10);
	count += ft_putchar((num % 10) + '0');
	return count;
}

int ft_puthex(unsigned int nb)
{
	int count = 0;
	char *base = "0123456789abcdef";

	if(nb >= 16)
		count += ft_puthex(nb / 16);
	count += ft_putchar(base[nb % 16]);
	return count;
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int     count = 0;
	int     i = 0;

	va_start(args, format);
	while(format[i])
	{
		if(format[i] == '%' && format[i + 1])
		{
			i++;
			if(format[i] == '%')
				count += ft_putchar('%');
			else if(format[i] == 's')
				count += ft_putstr(va_arg(args, char *));
			else if(format[i] == 'd')
				count += ft_putnbr(va_arg(args, int));
			else if(format[i] == 'x')
				count += ft_puthex(va_arg(args, unsigned int));
			else
				count += ft_putchar(format[i]);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

// // // x testare
// int	main(void)
// {
// 	ft_printf ("Test 01: Hello %s!\n", "world");
// 	printf ("Test 01 printf: Hello %s!\n", "world");

// 	ft_printf ("Test 02: %s\n", (char *)0);
// 	char *nullstr = NULL;
// 	printf("Test 02 printf: %s\n", nullstr ? nullstr : "(null)");

// 	ft_printf ("Test 03: Number: %d\n", 123456);
// 	printf ("Test 03 printf: Number: %d\n", 123456);

// 	ft_printf ("Test 04: Zero: %d\n", 0);
// 	printf ("Test 04 printf: Zero: %d\n", 0);

// 	ft_printf ("Test 05: Negative: %d\n", -42);
// 	printf ("Test 05 printf: Negative: %d\n", -42);

// 	ft_printf ("Test 06: Hex base: %x\n", 255);
// 	printf ("Test 06 printf: Hex base: %x\n", 255);

// 	ft_printf ("Test 07: Hex zero: %x\n", 0);
// 	printf ("Test 07 printf: Hex zero: %x\n", 0);

// 	ft_printf ("Test 08: Hex big: %x\n", 4294967295u);
// 	printf ("Test 08 printf: Hex big: %x\n", 4294967295u);

// 	ft_printf ("Test 09: %s %d %x\n", "combo", 42, 42);
// 	printf ("Test 09 printf: %s %d %x\n", "combo", 42, 42);

// 	ft_printf ("Test 10: Start-%s-End\n", "middle");
// 	printf ("Test 10 printf: Start-%s-End\n", "middle");

// 	return (0);
// }
