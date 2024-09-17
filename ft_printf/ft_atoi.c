#include "ft_printf.h"

int	ft_atoi(char *str)
{
	int	nb;
	int	sign;

	nb = 0;
	sign = 1;
	if (!str)
		return (0);
	while (*str && ((*str >= 7 && *str <= 13) || *str == ' '))
		str++;
	while (*str && (*str == '-' || *str == '+'))
		if (*str++ == '-')
			sign *= -1;
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + *str++ - '0';
	}
	return (nb * sign);
}

unsigned int	ft_atoui(char *str)
{
	unsigned int	nb;

	nb = 0;
	if (!str)
		return (0);
	while (*str && ((*str >= 7 && *str <= 13) || *str == ' '))
		str++;
	while (*str && (*str == '-' || *str == '+'))
		if (*str++ == '-')
			return (0);
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + *str++ - '0';
	}
	return (nb);
}
