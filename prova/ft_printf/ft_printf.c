#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return 1;
}

int	ft_putstr(char *str)
{
	int i = 0;
	int count = 0;

	if(!str)
		count += ft_putstr("(null)");
	while(str && str[i])
		count += ft_putchar(str[i++]);
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

int	ft_puthex(unsigned int nb)
{
	int	count = 0;
	char	*base = "0123456789abcdef";

	if(nb >= 16)
		count += ft_puthex(nb / 16);
	count += ft_putchar(base[nb % 16]);
	return count;
}

int	ft_printf(const char *format, ...)
{
	int	i = 0;
	int	count = 0;
	va_list	args;

	va_start(args, format);
	while(format[i])
	{
		if(format[i] == '%' && format[i + 1])
		{
			i++;
			if(format[i] == 's')
				count += ft_putstr(va_arg(args, char *));
			else if(format[i] == 'x')
				count += ft_puthex(va_arg(args, unsigned int));
			else if(format[i] == 'd')
				count += ft_putnbr(va_arg(args, int));
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

int	main()
{
	ft_printf("test 1: %s\n", "string");
	printf("printf test 2: %s\n", "string");

	printf("\n");

	ft_printf("test 2: %d\n", 32);
	printf("printf test 2: %d\n", 32);

	printf("\n");

	ft_printf("test 3: %d\n", -42);
	printf("printf test 3: %d\n", -42);

	printf("\n");

	ft_printf("test 4: %x\n", 255);
	printf("printf test4: %x\n", 255);

	printf("\n");
}
