#include "libft.h"

static int	int_check(long int num)
{
	if (num > 2147483647)
	{
		ft_putstr_fd("some arguments are bigger than an integer\n", 2);
		exit(-1);
	}
	if (num < -2147483648)
	{
		ft_putstr_fd("some arguments are smaller than an integer\n", 2);
		exit(-1);
	}
	return (num);
}

static void	char_check(char c)
{
	if (c > '9')
	{
		ft_putstr_fd("some arguments aren’t integers\n", 2);
		exit(-1);
	}
}

int	ft_atoi(char const *str)
{
	unsigned int	i;
	short int		minus;
	long int		num;

	num = 0;
	i = 0;
	minus = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' '
		|| str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = 1;
		i++;
	}
	while (str[i] != '\0')
	{
		char_check(str[i]);
		num = num * 10 + str[i] - '0';
		i++;
	}
	if (minus != 0)
		num *= -1;
	return (int_check(num));
}
