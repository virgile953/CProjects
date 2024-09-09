#include "strstr.h"

int	main(int argc, char **argv)
{
	t_file	*file;

	file = malloc(sizeof(t_file));
	if (!file)
		return (1);
	init_filestruct(file);
	if (argc < 2)
		return (display_error("There should be an agrument there!\n", file));
	file->filename = ft_strdup(argv[1]);
	if (!file->filename)
		return (display_error("Could not allocate filename in memory\n", file));
	if (!ft_get_content(file))
		return (display_error("There was a problem reading the file\n", file));
	ft_putstr(ft_strstr(file->content, argv[2]));
	return (display_error("File opened and closed gracefully\n", file));
}
