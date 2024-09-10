#include "strstr.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	while (*s1 && *s1 == *s2 && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	return ((n != 0) * (*s1 - *s2));
}

char	*ft_strstr(char *haystack, char *needle)
{
	int	needlelen;

	needlelen = ft_strlen(needle);
	if (needlelen == 0)
		return (haystack);
	while (*haystack)
		if (ft_strncmp(haystack++, needle, needlelen) == 0)
			return (haystack - 1);
	return (0);
}

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	write(1, str, ft_strlen(str));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
