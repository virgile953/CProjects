#include "strstr.h"

void	display_filenames(t_files *files)
{
	int	i;

	i = 0;
	while (i < files->nb_files)
	{
		printf("file %d: %s\n", i, files->files[i].filename);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_files	*files;
	int		i;

	files = init_filesstruct();
	get_filecount(".", files);
	printf("%d files\n", files->nb_files);
	if (init_input(files, argc, argv) == 1)
		return (1);
	// init files
	i = 0;
	get_filenames(".", files, &i);
	display_filenames(files);
	i = 0;
	while (i < files->nb_files)
	{
		if (!ft_get_content(&files->files[i]))
			return (display_error("There was a problem reading file\n", files));
		i++;
	}
	ft_putstr(ft_strstr(files[0].files[0].content, argv[2]));
	return (display_error("File opened and closed gracefully\n", files));
}

int	init_input(t_files *files, int argc, char **argv)
{
	int	i;

	(void)argv;
	i = 0;
	if (!files)
		return (display_error("Coul't malloc file struct in memory\n", files));
	files->files = malloc(sizeof(t_file) * (files->nb_files));
	if (!files->files)
		return (display_error("Coul't malloc file struct in memory\n", files));
	while (i < files->nb_files)
	{
		files->files[i].content = 0;
		files->files[i].fd = 0;
		files->files[i].content_len = 0;
		files->files[i].filename = 0;
		files->files[i++].filename = 0;
	}
	if (argc < 2)
		return (display_error("There should be an agrument there!\n", files));
	return (0);
}
