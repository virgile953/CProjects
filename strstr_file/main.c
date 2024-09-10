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
	if (init_input(files, argc) == 1)
		return (1);
	printf("%d files\n", files->nb_files);
	// display_filenames(files);
	i = 0;
	while (i < files->nb_files)
	{
		ft_putstr(ft_strstr(files->files[i].content, argv[2]));
		ft_close(&files->files[i]);
		i++;
	}
	return (error("File opened and closed gracefully\n", files));
}

int	init_input(t_files *files, int argc)
{
	int	i;

	i = 0;
	if (argc < 2)
		return (error("There should be an agrument there!\n", files));
	if (!files)
		return (error("Could not malloc files struct in memory\n", files));
	get_filecount(".", files);
	files->files = malloc(sizeof(t_file) * (files->nb_files));
	if (!files->files)
		return (error("Could not malloc file struct in memory\n", files));
	while (i < files->nb_files)
	{
		files->files[i].content = 0;
		files->files[i].fd = 0;
		files->files[i].content_len = 0;
		files->files[i++].filename = 0;
	}
	i = 0;
	get_filenames(".", files, &i);
	i = 0;
	while (i < files->nb_files)
		if (!ft_get_content(&files->files[i++]))
			return (error("There was a problem reading file\n", files));
	return (0);
}
