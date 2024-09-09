#include "strstr.h"

void	get_filecount(char *path, t_files *files)
{
	DIR				*d;
	struct dirent	*dir;
	char			full_path[512];

	d = opendir(path);
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			if (ft_strncmp(dir->d_name, ".", 1) == 0)
				continue ;
			full_path[0] = '\0';
			get_fullname(full_path, path, dir);
			if (dir->d_type == FT_REG)
				files->nb_files++;
			if (dir->d_type == FT_DIR)
				get_filecount(full_path, files);
		}
		closedir(d);
	}
}

void	get_filenames(char *path, t_files *files, int *i)
{
	DIR				*d;
	struct dirent	*dir;
	char			full_path[512];

	d = opendir(path);
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			if (ft_strncmp(dir->d_name, ".", 1) == 0)
				continue ;
			full_path[0] = '\0';
			get_fullname(full_path, path, dir);
			if (dir->d_type == FT_REG)
			{
				files->files[*i].filename = ft_strdup(full_path);
				*i = *i + 1;
			}
			if (dir->d_type == FT_DIR)
				get_filenames(full_path, files, i);
		}
			closedir(d);
	}
}

void	get_fullname(char full_path[512], char *path, struct dirent *dir)
{
	ft_strcat(full_path, path);
	ft_strcat(full_path, "/");
	ft_strcat(full_path, dir->d_name);
}
