#include "strstr.h"

int	handle_args(int argc, char **argv, t_files *files)
{
	if (argc < 2)
		return (error("There should be an agrument there!\n", files));
	if (argc == 3)
		files->basepath = ft_strdup(argv[1]);
	else
		files->basepath = ft_strdup(".");
	return (0);
}
