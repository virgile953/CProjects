#ifndef STRSTR_H
# define STRSTR_H
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define BUF_SIZE 4096
# define MAX_SIZE 2147483647
# define FT_REG 8
# define FT_DIR 4

typedef struct s_file
{
	int		fd;
	char	*filename;
	char	*content;
	size_t	content_len;
}			t_file;

typedef struct s_files
{
	t_file	*files;
	int		nb_files;
	char	*basepath;
}			t_files;

int			ft_strlen(char *str);
int			ft_strncmp(char *s1, char *s2, int n);
char		*ft_strstr(char *haystack, char *needle);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strdup(char *src);
void		ft_putstr(char *str);
void		ft_putchar(char c);
int			error(char *error, t_files *files);
int			ft_open(t_file *file);
int			ft_close(t_file *file);
int			ft_get_content(t_file *file);
int			get_file_len(t_file *file);
void		ft_putnbr(int nb);
int			ft_atoi(char *str);
void		free_file(t_file *file);
void		free_files(t_files *files);
t_files		*init_filesstruct(void);
void		init_filestruct(t_file *file);
int			init_input(t_files *files, int argc, char **argv);
char		*ft_strcat(char *dest, char *src);
void		get_filecount(char *path, t_files *files);
void		get_fullname(char full_path[512], char *path, struct dirent *dir);
void		get_filenames(char *path, t_files *files, int *i);
int			handle_args(int argc, char **argv, t_files *files);
int			is_elf_file(char *file);

#endif
