#include "ft_printf.h"

int	main(int argc, char **argv)
{
	char	*itoa;
	char	*uitoa;
	int		pad_size;

	if (argc < 2)
		exit(1);
	if (argc == 3)
		pad_size = ft_atoi(argv[2]);
	else
		pad_size = 0;
	uitoa = ft_uitoa(ft_atoui(argv[1]), pad_size);
	if (!((long)ft_atoui(argv[1]) > (long)ft_atoi(argv[1])))
	{
		itoa = ft_itoa(ft_atoi(argv[1]), pad_size);
		printf("itoa: %s\n", itoa);
		printf("len: %d\n", ft_strlen(itoa));
		free(itoa);
	}
	printf("uitoa: %s\n", uitoa);
	printf("len: %d\n", ft_strlen(uitoa));
	free(uitoa);
}
