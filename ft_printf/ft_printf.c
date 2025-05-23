/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:31:18 by vhacman           #+#    #+#             */
/*   Updated: 2025/05/23 16:42:29 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char	*str)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	long	num;
	int		count;

	num = nb;
	count = 0;
	if (num < 0)
	{
		count += ft_putchar('-');
		num = -num;
	}
	if (num >= 10)
		count += ft_putnbr(num / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}

int	ft_puthex(unsigned int nb)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
		ft_puthex(nb / 16);
	count = count + ft_putchar(base[nb % 16]);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;
	int			i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 's')
				count = count + ft_putstr(va_arg(args, char *));
			else if (format[i] == 'd')
				count = count + ft_putnbr(va_arg(args, int));
			else if (format[i] == 'x')
				count = count + ft_puthex(va_arg(args, unsigned int));
			else
				count = count + ft_putchar(format[i]);
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	ft_printf ("Test 01: Hello %s!\n", "world");
	ft_printf ("Test 02: %s\n", (char *)0);
	ft_printf ("Test 03: Number: %d\n", 123456);
	ft_printf ("Test 04: Zero: %d\n", 0);
	ft_printf ("Test 05: Negative: %d\n", -42);
	ft_printf ("Test 06: Hex base: %x\n", 255);
	ft_printf ("Test 07: Hex zero: %x\n", 0);
	ft_printf ("Test 08: Hex big: %x\n", 4294967295u);
	ft_printf ("Test 09: %s %d %x\n", "combo", 42, 42);
	ft_printf ("Test 10: Start-%s-End\n", "middle");
	return (0);
}
