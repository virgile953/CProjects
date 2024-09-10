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
	if (init_input(files, argc, argv) == 1)
		return (1);
	printf("%d files\n", files->nb_files);
	// display_filenames(files);
	i = 0;
	while (i < files->nb_files)
	{
		printf("file read: %s / size : %ld / content len: %d / fd: %d\n",
			files->files[i].filename, files->files[i].content_len,
			ft_strlen(files->files[i].content), files->files[i].fd);
		if (argc == 3)
			ft_putstr(ft_strstr(files->files[i].content, argv[2]));
		ft_close(&files->files[i]);
		i++;
	}
	return (error("File opened and closed gracefully\n", files));
}

int	init_input(t_files *files, int argc, char **argv)
{
	int	i;

	i = 0;
	if (handle_args(argc, argv, files) == 1)
		return (error("Arguments don't math requirements!\n", files));
	if (!files)
		return (error("Could not malloc files struct in memory\n", files));
	get_filecount(files->basepath, files);
	files->files = malloc(sizeof(t_file) * (files->nb_files));
	if (!files->files)
		return (error("Could not malloc file struct in memory\n", files));
	while (i < files->nb_files)
		init_filestruct(&files->files[i++]);
	i = 0;
	get_filenames(files->basepath, files, &i);
	i = 0;
	while (i < files->nb_files)
	{
		if (!ft_get_content(&files->files[i++]))
			return (error("There was a problem reading file\n", files));
	}
	return (0);
}
