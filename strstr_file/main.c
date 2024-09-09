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
	file->filename = ft_strdup(argv[1]);
	if (!file->filename)
		return (display_error("Could not allocate filename in memory\n", file));
	file->content_len = get_file_len(file);
	if (file->content_len == 0)
		return (display_error("there was a problem reading the file\n", file));

	return (display_error("file opened and closed gracefully\n", file));
}
