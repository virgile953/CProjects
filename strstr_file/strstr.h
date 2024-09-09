#ifndef STRSTR_H
# define STRSTR_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define BUF_SIZE 4096
# define MAX_SIZE 2147483647

typedef struct s_file
{
	int		fd;
	char	*filename;
	char	*content;
	size_t	content_len;
}			t_file;

int			ft_strlen(char *str);
int			ft_strncmp(char *s1, char *s2, int n);
char		*ft_strstr(char *haystack, char *needle);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strdup(char *src);
void		ft_putstr(char *str);
int			display_error(char *error, t_file *file);
int			ft_open(t_file *file);
int			ft_close(t_file *file);
size_t		get_file_len(t_file *file);

#endif
