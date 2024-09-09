#include "strstr.h"

int	ft_open(t_file *file)
{
	file->fd = open(file->filename, O_RDONLY);
	if (file->fd >= 0)
		return (file->fd);
	return (0);
}

int	ft_close(t_file *file)
{
	if (file->fd >= 0)
	{
		file->fd = close(file->fd);
		if (file->fd != 0)
			return (0);
		return (1);
	}
	return (1);
}

int	open_file(t_file *file)
{
}

size_t	get_file_len(t_file *file)
{
	size_t	size;
	size_t	total_size;
	char	buf[BUF_SIZE];

	if (!file->fd)
		if (!ft_open(file))
			return (0);
	while (1)
	{
		size = read(file->fd, buf, BUF_SIZE);
		total_size += size;
		if (size < BUF_SIZE)
		{
			if (!ft_close(file))
				return (0);
			return (total_size);
		}
		if (total_size > MAX_SIZE)
			return (0);
	}
	return (0);
}
