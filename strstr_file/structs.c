#include "strstr.h"

void	free_file_content(t_file *file)
{
	if (file->fd)
		ft_close(file);
	if (file->content)
		free(file->content);
	if (file->filename)
		free(file->filename);
}

void	init_filestruct(t_file *file)
{
	file->content = 0;
	file->fd = 0;
	file->content_len = 0;
	file->filename = 0;
}

t_input	*init_tinput(void)
{
	t_input	*input;

	input = malloc(sizeof(t_input));
	if (!input)
		return (NULL);
	input->args = 0;
	input->count = 0;
	input->path = 0;
	input->to_find = 0;
	return (input);
}

t_files	*init_filesstruct(void)
{
	t_files	*files;

	files = malloc(sizeof(t_files));
	if (!files)
		return (NULL);
	files->nb_files = 0;
	files->files = 0;
	files->basepath = 0;
	return (files);
}

void	free_file(t_file *file)
{
	if (file)
	{
		free_file_content(file);
		free(file);
	}
}

void	free_files(t_files *files)
{
	int	i;

	i = 0;
	if (files)
	{
		while (i < files->nb_files)
			free_file_content(&files->files[i++]);
		i++;
		if (files->files)
			free(files->files);
		if (files->basepath)
			free(files->basepath);
		free(files);
	}
}
