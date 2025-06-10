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
<<<<<<< HEAD
	
	if(str == NULL)
=======

	if(!str)
>>>>>>> c8413ff (ok)
		return(ft_putstr("(null)"));
	while(*str)
		count += ft_putchar(*str++);
	return count;
}

int	ft_putnbr(int nb)
{
	long n = nb;
	int count = 0;

<<<<<<< HEAD
	 if(n < 0)
	 {
		 count += ft_putchar('-');
		 n = -n;
	 }
	 if(n >= 10)
	 	count += ft_putnbr(n / 10);
	 count += ft_putchar((n % 10) + '0');
	 return count;
=======
	if(n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if(n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar((n % 10) + '0');
	return count;
>>>>>>> c8413ff (ok)
}

int	ft_puthex(int n)
{
	int count = 0;
	char *base = "0123456789abcdef";

	if(n >= 16)
<<<<<<< HEAD
		count += ft_puthex(n % 16);
=======
		count += ft_puthex(n / 16);
>>>>>>> c8413ff (ok)
	count += ft_putchar(base[n % 16]);
	return count;
}

<<<<<<< HEAD

int ft_printf(const char *format, ...)
{

	int count = 0;
	int i = 0;
	va_list args;

=======
int	ft_printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i = 0;

>>>>>>> c8413ff (ok)
	va_start(args, format);
	while(format[i])
	{
		if(format[i] == '%' && format[i + 1])
		{
			i++;
<<<<<<< HEAD
			if(format[i] == 'd')
				count += ft_putnbr(va_arg(args, int));
			else if(format[i] == 's')
				count += ft_putstr(va_arg(args, char *));
=======
			if(format[i] == 's')
				count += ft_putstr(va_arg(args, char *));
			else if(format[i] == 'd')
				count += ft_putnbr(va_arg(args, int));
>>>>>>> c8413ff (ok)
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

<<<<<<< HEAD

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

	
=======
// #include <stdio.h>

// int	main(void)
// {
// 	ft_printf("Test1: %s\n", "Hello World");
// 	printf("Test1 printf: %s\n", "Hello World");
// 	ft_printf("Test2: %d\n", 1234567);
// 	printf("Test2: %d\n", 1234567);
// 	ft_printf("Test 05: %d\n", -42);
// 	printf("Test 05 printf: %d\n", -42);
// 	printf("\n");
// 	ft_printf("Test 06: Hex base: %x\n", 255);
// 	printf("Test 06 printf: Hex base: %x\n", 255);
// 	ft_printf("Test 07: Hex zero: %x\n", 0);
// 	printf("Test 07 printf: Hex zero: %x\n", 0);
// 	ft_printf("Test 08: Hex big: %x\n", 4294967295u);
// 	printf("Test 08 printf: Hex big: %x\n", 4294967295u);
// }
>>>>>>> c8413ff (ok)
