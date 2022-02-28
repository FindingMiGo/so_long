#include "so_long.h"

static void	*free_charptr(char **line, char **tmp)
{
	free(*line);
	*line = NULL;
	free(*tmp);
	*tmp = NULL;
}

static char	*call_gnl(int fd)
{
	char	*join;
	char	*tmp;
	char	*line;

	join = NULL;
	line = NULL;
	tmp = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tmp = join;
		join = ft_strjoin(join, line);
		if (!join)
		{
			free_charptr(&line, &tmp);
			error_exit(MLC_ERR);
		}
		free_charptr(&line, &tmp);
	}
	free_charptr(&line, &tmp);
	return (join);
}

char	*ber_to_line(char **av)
{
	int		fd;
	char	*join;

	fd = open(av[0], O_RDONLY);
	if (fd == -1)
		error_exit(OPENFILE_ERR);
	join = call_gnl(fd);
	if (!join)
		error_exit(EMPTY_ERR);
	if (close(fd) == -1)
	{
		free(join);
		error_exit(OPENFILE_ERR);
	}
	return (join);
}
