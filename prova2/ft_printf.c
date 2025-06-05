#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return 1;
}

int	ft_putstr(char *str)
{
	int count = 0;

	if(str == NULL)
		return(ft_putstr("(null)"));
	while(*str)
		count += ft_putchar(*str++);
	return count;
}

int	ft_putnbr(int nb)
{
	long n = nb;
	int count = 0;

	if(n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if(n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar((n % 10) + '0'); 
	return count;
}

int	ft_puthex(unsigned int n)
{
	int count = 0;
	char *base = "0123456789abcdef";
	if(n >= 16)
		count += ft_puthex(n / 16);
	count += ft_putchar(base[n % 16]);
	return count;
}

int	ft_printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	int i = 0;

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
	return count;
}

#include <stdio.h>
int	main(void)
{
	ft_printf ("Test 01: Hello %s!\n", "world");
	printf ("Test 01 printf: Hello %s!\n", "world");
	ft_printf ("Test 03: Number: %d\n", 123456);
	printf ("Test 03 printf: Number: %d\n", 123456);
	ft_printf ("Test 05: Negative: %d\n", -42);
	printf ("Test 05 printf: Negative: %d\n", -42);
	ft_printf ("Test 06: Hex base: %x\n", 255);
	printf ("Test 06 printf: Hex base: %x\n", 255);
	ft_printf ("Test 08: Hex big: %x\n", 4294967295u);
	printf ("Test 08 printf: Hex big: %x\n", 4294967295u);
	ft_printf ("Test 09: %s %d %x\n", "combo", 42, 42);
	printf ("Test 09 printf: %s %d %x\n", "combo", 42, 42);
}
