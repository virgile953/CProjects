#include "strstr.h"

int	get_line(char *content, char *to_find)
{
	int		line;
	char	*match;
	char	*i;

	line = 1;
	match = ft_strstr(content, to_find);
	if (!match)
		return (-1);
	i = content;
	while (i < match)
	{
		if (*i == '\n')
			line++;
		i++;
	}
	return (line);
}

int	get_col(char *content, char *to_find)
{
	char	*match;
	char	*line_start;

	match = ft_strstr(content, to_find);
	if (!match)
		return (-1);
	line_start = match;
	while (line_start > content && *(line_start - 1) != '\n')
		line_start--;
	return (match - line_start + 1);
}

void	print_results(t_result *result)
{
	int	i;

	i = 0;
	while (result[i].file)
	{
		ft_putstr(result[i].filename);
		ft_putstr(": l");
		ft_putnbr(result[i].line);
		ft_putstr(": c");
		ft_putnbr(result[i].col);
		ft_putstr("\n");
		i++;
	}
	free(result);
}

t_result	*get_result(t_input *input, t_files *files)
{
	int			i;
	int			j;
	int			nbres;
	t_result	*res;

	j = 0;
	nbres = 0;
	i = 0;
	while (i < files->nb_files)
		if (ft_strstr(files->files[i++].content, input->to_find))
			nbres++;
	res = malloc(sizeof(t_result) * (nbres + 1));
	i = 0;
	while (i < files->nb_files)
	{
		if (ft_strstr(files->files[i++].content, input->to_find))
		{
			res[j].file = &files->files[i - 1];
			res[j].filename = files->files[i - 1].filename;
			res[j].line = get_line(files->files[i - 1].content, input->to_find);
			res[j++].col = get_col(files->files[i - 1].content, input->to_find);
		}
	}
	res[j].file = 0;
	return (res);
}
