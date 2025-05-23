#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/* Writes a single character and returns 1 */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/* Writes a string, handles NULL pointer */
int	ft_putstr(char *str)
{
	int	i = 0;

	if (str == NULL)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

/* Writes a decimal integer */
int	ft_putnbr(int n)
{
	int	count = 0;

	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		ft_putchar('-');
		count++;
		n = -n;
	}
	if (n >= 10)
		count = count + ft_putnbr(n / 10);
	char c = n % 10 + '0';
	ft_putchar(c);
	count++;
	return (count);
}

/* Writes an unsigned integer in hexadecimal */
int	ft_putnbr_hex(unsigned int n)
{
	char	*hex = "0123456789abcdef";
	int		count = 0;

	if (n >= 16)
		count = count + ft_putnbr_hex(n / 16);
	ft_putchar(hex[n % 16]);
	count++;
	return (count);
}

/* Handles supported format specifiers */
int	handle_conversion(char specifier, va_list args)
{
	if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (specifier == 'x')
		return (ft_putnbr_hex(va_arg(args, unsigned int)));
	return (0);
}

/* Custom printf implementation supporting %s, %d, %x */
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i = 0;
	int		count = 0;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += handle_conversion(format[i], args);
		}
		else
		{
			ft_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

#include <stdio.h>

int	main(void)
{
	// Test stringa normale
	ft_printf("Test 01: Hello %s!\n", "world");
	// Test stringa NULL
	ft_printf("Test 02: %s\n", (char *)0);
	// Test numero positivo
	ft_printf("Test 03: Number: %d\n", 123456);
	// Test numero zero
	ft_printf("Test 04: Zero: %d\n", 0);
	// Test numero negativo
	ft_printf("Test 05: Negative: %d\n", -42);
	// Test hex base
	ft_printf("Test 06: Hex base: %x\n", 255);
	// Test hex con 0
	ft_printf("Test 07: Hex zero: %x\n", 0);
	// Test hex grande
	ft_printf("Test 08: Hex big: %x\n", 4294967295u); // UINT_MAX

	// Test combinato
	ft_printf("Test 09: %s %d %x\n", "combo", 42, 42);
	// Test mix stringhe con spazi
	ft_printf("Test 10: Start-%s-End\n", "middle");

	return (0);
}

