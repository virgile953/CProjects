#include "strstr.h"

int	main(int argc, char **argv)
{
	t_file	*file;

	file = malloc(sizeof(t_file));
	if (!file)
		return (1);
	file->content = 0;
	file->fd = 0;
	file->content_len = 0;
	file->filename = 0;
	file->filename = ft_strdup(argv[1]);
	if (!file->filename)
		return (display_error("Could not allocate filename in memory\n", file));
	if (!ft_get_content(file))
	{
		printf("content len: %ld\n", file->content_len);
		return (display_error("there was a problem reading the file\n", file));
	}
	ft_putstr(file->content);
	return (display_error("file opened and closed gracefully\n", file));
}
