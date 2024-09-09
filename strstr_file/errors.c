#include "strstr.h"

int	display_error(char *error, t_file *file)
{
	free_file(file);
	ft_putstr(error);
	return (1);
}
