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
	file->filename = 0;
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
		while (files->nb_files < i)
		{
			free_file_content(files[i].files);
			i++;
		}
		free(files);
	}
}
