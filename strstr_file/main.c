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
	t_files		*files;
	t_input		*input;
	t_result	*result;

	input = init_tinput();
	files = init_filesstruct();
	if (init_input(files, argc, argv, input) == 1)
		return (1);
	printf("%d files\n", files->nb_files);
	// display_filenames(files);
	if (!input->to_find)
		return (error("Arguments invalid!\n", files));
	result = get_result(input, files);
	if (result)
		print_results(result);
	return (error("File opened and closed gracefully\n", files));
}

int	init_input(t_files *files, int argc, char **argv, t_input *input)
{
	int	i;

	i = 0;
	if (handle_args(argc, argv, files, input) == 1)
		return (error("Arguments don't match requirements!\n", files));
	if (!files)
		return (error("Could not malloc files struct in memory\n", files));
	get_filecount(input->path, files);
	files->files = malloc(sizeof(t_file) * (files->nb_files));
	if (!files->files)
		return (error("Could not malloc file struct in memory\n", files));
	while (i < files->nb_files)
		init_filestruct(&files->files[i++]);
	i = 0;
	get_filenames(input->path, files, &i);
	i = 0;
	while (i < files->nb_files)
	{
		if (!ft_get_content(&files->files[i++]))
			return (error("There was a problem reading file\n", files));
	}
	return (0);
}
