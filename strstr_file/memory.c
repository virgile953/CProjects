#include "strstr.h"

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

void	free_file_content(t_file *file)
{
	if (file->fd)
		ft_close(file);
	if (file->content)
		free(file->content);
	if (file->filename)
		free(file->filename);
}
void	free_file(t_file *file)
{
	if (file)
	{
		free_file_content(file);
		free(file);
	}
}
