#include"so_long.h"

static void
	count_object(char *mapline, size_t *pcount, size_t *icount, size_t *gcount)
{
	size_t	i;

	i = 0;
	while (mapline[i])
	{
		if (mapline[i] == PLAYER)
			(*pcount)++;
		else if (mapline[i] == ITEM)
			(*icount)++;
		else if (mapline[i] == GOAL)
			(*gcount)++;
		i++;
	}
}

int	validate_map(char *mapline, t_param *param)
{
	size_t	pcount;
	size_t	gcount;
	size_t	icount;

	pcount = 0;
	gcount = 0;
	icount = 0;
	count_object(mapline, &pcount, &icount, &gcount);
	if (pcount != 1 || gcount < 1 || icount < 1)
	{
		free(mapline);
		error_exit(MAP_ERR);
	}
	if (!is_validchr(mapline))
	{
		free(mapline);
		error_exit(CHR_ERR);
	}
	if (is_blankline_insertion(mapline))
	{
		free(mapline);
		error_exit(WALL_ERR);
	}
	param->gotcha = icount;
	return (1);
}

static int	is_only_wall(char *map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != WALL)
			return (0);
		i++;
	}
	return (1);
}

static int	is_bothends_wall(char **map)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (len != ft_strlen(map[i]))
			error_exit(SHAPE_ERR);
		if (map[i][0] != WALL || map[i][len - 1] != WALL)
			return (0);
		i++;
	}
	return (1);
}

int	is_rectangle(char **map, t_vars *vars)
{
	if (!is_bothends_wall(map))
		return (0);
	if (!is_only_wall(map[0]))
		return (0);
	if (!is_only_wall(map[get_rowsize(map) - 1]))
		return (0);
	return (1);
}
