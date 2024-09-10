#include "strstr.h"

char	*ft_strcpy(char *dest, char *src)
{
	char	*ret;

	ret = dest;
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	return (ret);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*ret;

	len = ft_strlen(src);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ft_strcpy(ret, src);
	ret[len] = 0;
	return (ret);
}

char	*ft_strcat(char *dest, char *src)
{
	int	lendest;

	lendest = ft_strlen(dest);
	while (*src)
		dest[lendest++] = *src++;
	dest[lendest] = 0;
	return (dest);
}
