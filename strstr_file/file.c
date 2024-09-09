#include "strstr.h"

int	ft_open(t_file *file)
{
	if (file->fd == 0)
		if (!ft_close(file))
			return (0);
	file->fd = open(file->filename, O_RDONLY);
	if (file->fd >= 0)
		return (1);
	return (0);
}

int	ft_close(t_file *file)
{
	if (file->fd > 0)
	{
		file->fd = close(file->fd);
		if (file->fd != 0)
			return (0);
	}
	return (1);
}

int	ft_get_content(t_file *file)
{
	size_t	sizeread;

	if (!get_file_len(file))
		return (0);
	if (!ft_open(file))
		return (0);
	file->content = malloc(sizeof(char) * (file->content_len + 1));
	if (!file->content)
		return (0);
	sizeread = read(file->fd, file->content, file->content_len);
	if (sizeread != file->content_len)
		return (0);
	file->content[file->content_len] = '\0';
	return (1);
}

size_t	get_file_len(t_file *file)
{
	size_t	size;
	char	buf[BUF_SIZE];

	if (!file->fd)
		if (!ft_open(file))
			return (0);
	while (1)
	{
		size = read(file->fd, buf, BUF_SIZE);
		file->content_len += size;
		if (size < BUF_SIZE)
		{
			if (!ft_close(file))
				return (0);
			if (!ft_open(file))
				return (0);
			return (file->content_len);
		}
		if (file->content_len > MAX_SIZE)
			return (0);
	}
	return (0);
}
