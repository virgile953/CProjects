#include "strstr.h"

int	display_error(char *error, t_file *file)
{
	if (file->fd)
		ft_close(file);
	if (file->content)
		free(file->content);
	if (file->filename)
		free(file->filename);
	ft_putstr(error);
	return (1);
}
