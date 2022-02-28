#include"so_long.h"

int	is_valid_filename(char **input)
{
	char	*dot;
	int		ext;

	dot = ft_strrchr(input[0], '.');
	if (!dot)
		return (0);
	ext = ft_strncmp(dot, ".ber", 5);
	if (!ext)
		return (1);
	return (0);
}

int	is_validchr(char *line)
{
	size_t		i;
	const char	*c = "10PCE\n";

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(c, line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_blankline_insertion(char *line)
{
	char	*cnl;
	size_t	i;

	i = 0;
	cnl = ft_strnstr(line, "\n\n", ft_strlen(line));
	while (cnl && cnl[i])
	{
		if (cnl[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	check_arg(int ac, char **av)
{
	if (ac != 1)
		error_exit(ARG_ERR);
	if (!is_valid_filename(av))
		error_exit(FNAME_ERR);
}
