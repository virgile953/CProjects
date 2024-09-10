#include "strstr.h"

int	error(char *error, t_files *files, t_input *input)
{
	free_files(files);
	if (input->path)
		free(input->path);
	if (input->to_find)
		free(input->to_find);
	free(input);
	ft_putstr(error);
	return (1);
}
