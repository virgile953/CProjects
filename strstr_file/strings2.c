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
	return (ret);
}
