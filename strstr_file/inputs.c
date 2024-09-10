#include "strstr.h"

int	handle_args(int argc, char **argv, t_files *files, t_input *input)
{
	if (argc < 2)
		return (error("There should be an agrument there!\n", files, input));
	input->args = &argv[1];
	input->count = argc - 1;
	if (argc == 3)
	{
		files->basepath = ft_strdup(argv[1]);
		input->to_find = ft_strdup(argv[2]);
	}
	else
	{
		files->basepath = ft_strdup(".");
		input->to_find = ft_strdup(argv[1]);
	}
	input->path = ft_strdup(files->basepath);
	return (0);
}
