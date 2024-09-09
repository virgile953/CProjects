#include "strstr.h"
#include <dirent.h>
#include <errno.h>

void	open_dir(char *path)
{
	DIR				*d;
	struct dirent	*dir;
	char			full_path[512];

	d = opendir(path);
	if (d)
	{
		dir = readdir(d);
		while (dir != NULL)
		{
			if (ft_strncmp(dir->d_name, ".", 1) == 0)
			{
				dir = readdir(d);
				continue ;
			}
			full_path[0] = '\0';
			MakeFullName(full_path, path, dir);
			if (dir->d_type == FT_REG)
				printf("%s\n", full_path);
			if (dir->d_type == FT_DIR)
				open_dir(full_path);
			dir = readdir(d);
		}
		closedir(d);
	}
}

void	MakeFullName(char full_path[512], char *path, struct dirent *dir)
{
	ft_strcat(full_path, path);
	ft_strcat(full_path, "/");
	ft_strcat(full_path, dir->d_name);
}
