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

	if (str == NULL)
	{
		count = ft_putstr("(null)");
		return (count);
	}
	while (str[i] != '\0')
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int	count = 0;

	if (n == -2147483648)
		count = ft_putstr("-2147483648");
	else if (n < 0)
	{
		count = ft_putchar('-');
		count += ft_putnbr(-n);
	}
	else
	{
		if (n > 9)
		{
			count = ft_putnbr(n / 10);
			count += ft_putnbr(n % 10);
		}
		else
			count = ft_putchar(n + '0');
	}
	return (count);
}

int	ft_puthex(unsigned int n)
{
	int	count = 0;

	if (n >= 16)
	{
		count = ft_puthex(n / 16);
		count += ft_puthex(n % 16);
	}
	else
	{
		if (n <= 9)
			count = ft_putnbr(n);
		else
			count = ft_putchar(n - 10 + 'a');
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
				count += ft_putstr(va_arg(arg_lst, char *));
			else if (fst_arg[i] == 'd')
				count += ft_putnbr(va_arg(arg_lst, int));
			else if (fst_arg[i] == 'x')
				count += ft_puthex(va_arg(arg_lst, unsigned int));
			else if (fst_arg[i] == '%')
				count += ft_putchar(fst_arg[i]);
		}
		else
			count += ft_putchar(fst_arg[i]);
		i++;
	}
	va_end(arg_lst);
	return (count);
}

/* int	main(void)
{
	int	ft = 0;
	int	og = 0;
	char *str = NULL;

	ft = ft_printf("ft: hola/\n");
	og = printf("og: hola/\n");
	printf ("ft: %d - og: %d/\n\n", ft, og);

	ft = ft_printf("ft: <%s>/\n", str);
	og = printf("og: <%s>/\n", str);
	printf ("ft: %d - og: %d/\n\n", ft, og);

	ft = ft_printf("ft: %d/\n", 2345);
	og = printf("og: %d/\n", 2345);
	printf ("ft: %d - og: %d\n\n", ft, og);

	ft = ft_printf("ft: %d -> %x/\n", 429876, 429876);
	og = printf("og: %d -> %x/\n", 429876, 429876);
	printf ("ft: %d - og: %d/\n", ft, og);

	return (0);
} */