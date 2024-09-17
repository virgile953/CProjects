#include "ft_printf.h"

int	ft_getulen(unsigned int nbr)
{
	int	i;

	i = 1;
	while (nbr / 10 > 0)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

int	ft_getlen(long nbr)
{
	int	i;
	int	isneg;

	isneg = 0;
	i = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		isneg = 1;
	}
	while (nbr / 10 > 0)
	{
		i++;
		nbr /= 10;
	}
	return (i + isneg);
}

char	*ft_itoa(long nbr, int pad)
{
	int		i;
	int		neg;
	char	*buffer;
	int		malloc_size;

	malloc_size = ((pad - ft_getlen(nbr) >= 0) * pad) + ((ft_getlen(nbr)
				- pad > 0) * ft_getlen(nbr));
	buffer = malloc(malloc_size + 1 + (nbr < 0));
	if (!buffer)
		return (NULL);
	neg = 0;
	i = 0;
	if (nbr < 0 && ++neg)
		nbr = -nbr;
	while (nbr > 0)
	{
		buffer[i++] = (nbr % 10) + '0';
		nbr /= 10;
	}
	while (i + neg < malloc_size)
		buffer[i++] = '0';
	buffer[i] = neg * '-';
	return (ft_rev_str(buffer));
}

char	*ft_uitoa(unsigned int nbr, int pad)
{
	int		i;
	char	*buffer;
	int		malloc_size;

	malloc_size = ((pad - ft_getulen(nbr) >= 0) * pad) + ((ft_getulen(nbr)
				- pad > 0) * ft_getulen(nbr));
	buffer = malloc(malloc_size + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	while (nbr > 0)
	{
		buffer[i++] = (nbr % 10) + '0';
		nbr /= 10;
	}
	while (i < malloc_size)
		buffer[i++] = '0';
	buffer[i] = 0;
	return (ft_rev_str(buffer));
}
