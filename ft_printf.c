#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i = 0;
	int	count = 0;

	while (str[i] != '\0')
	{
		count = count + ft_putchar(str[i]);
		i++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int	count = 0;

	if (n < 0)
	{
		count = count + ft_putchar('-');
		count = count + ft_putnbr(n * -1);
	}
	else
	{
		if (n > 9)
		{
			count = count + ft_putnbr(n / 10);
			count = count + ft_putnbr(n % 10);
		}
		else
			count = count + ft_putchar(n + '0');
	}
	return (count);
}

int	ft_puthex(unsigned int n)
{
	int	count = 0;

	if (n >= 16)
	{
		count = count + ft_puthex(n / 16);
		count = count + ft_puthex(n % 16);
	}
	else
	{
		if (n <= 9)
			count = count + ft_putnbr(n);
		else
			count = count + ft_putchar(n - 10 + 'a');
	}
	return (count);
}

int	ft_printf(char *fst_arg, ...)
{
	va_list	arg_lst;
	int		count = 0;
	int		i = 0;

	va_start(arg_lst, fst_arg);
	while (fst_arg[i])
	{
		if (fst_arg[i] == '%')
		{
			i++;
			if (fst_arg[i] == 's')
				count = count + ft_putstr(va_arg(arg_lst, char *));
			else if (fst_arg[i] == 'd')
				count = count + ft_putnbr(va_arg(arg_lst, int));
			else if (fst_arg[i] == 'x')
				count = count + ft_puthex(va_arg(arg_lst, unsigned int));
			else if (fst_arg[i] == '%')
				count = count + ft_putchar(fst_arg[i]);
		}
		else
			count = count + ft_putchar(fst_arg[i]);
		i++;;
	}
	va_end(arg_lst);
	return (count);
}

int	main(void)
{
	int	ft = 0;
	int	og = 0;

	ft = ft_printf("ft: hola/\n");
	og = printf("og: hola/\n");
	printf ("ft: %d - og: %d/\n\n", ft, og);

	ft = ft_printf("ft: un string <%s>/\n", "abcdef123456");
	og = printf("og: un string <%s>/\n", "abcdef123456");
	printf ("ft: %d - og: %d/\n\n", ft, og);

	ft = ft_printf("ft: %d es el numero %d menos %d/\n", 2345, 103, 23);
	og = printf("og: %d es el numero %d menos %d/\n", 2345, 103, 23);
	printf ("ft: %d - og: %d\n\n", ft, og);

	ft = ft_printf("ft: el numero %d es %x en hex/\n", 429876, 429876);
	og = printf("og: el numero %d es %x en hex/\n", 429876, 429876);
	printf ("ft: %d - og: %d/\n", ft, og);

	return (0);
}
