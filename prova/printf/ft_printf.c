#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return 1;
}

int	ft_putstr(char	*str)
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
		count += ft_puthex(n % 16);
	count += ft_putchar(base[n % 16]);
	return count;
}


int ft_printf(const char *format, ...)
{

	int count = 0;
	int i = 0;
	va_list args;

	va_start(args, format);
	while(format[i])
	{
		if(format[i] == '%' && format[i + 1])
		{
			i++;
			if(format[i] == 'd')
				count += ft_putnbr(va_arg(args, int));
			else if(format[i] == 's')
				count += ft_putstr(va_arg(args, char *));
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


int	main(void)
{
	char	*string = "string";
	ft_printf("test1: %s\n", string);
	printf("test1: %s\n", string);
	printf("\n");

	int a = 42;
	ft_printf("test2: %d\n", a);
	printf("test2: %d\n", a);
	printf("\n");

	ft_printf("test3: %x\n", 255);
	printf("test3: %x\n", 255);
	printf("\n");
}

	
