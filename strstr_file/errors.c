#include "strstr.h"

int	display_error(char *error, t_files *files)
{
	free_files(files);
	ft_putstr(error);
	return (1);
}
