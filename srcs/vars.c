#include "so_long.h"

void	free_map(char **lines)
{
	size_t	i;

	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		lines[i] = NULL;
		i++;
	}
	free(lines);
	lines = NULL;
}

void	free_param(char **map, t_imgs *imgs, t_vars *vars, t_param *param)
{
	if (vars && vars->mlx)
		mlx_loop_end(vars->mlx);
	if (vars && vars->mlx && vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (map)
		free_map(map);
	if (vars && vars->mlx && imgs)
		free_imgs(vars->mlx, imgs);
	if (vars && vars->mlx)
		free_mlx(vars->mlx);
	if (vars)
		free(vars);
	if (param)
		free(param);
}

int	vars_storage(char **mapp, t_imgs *imgsp, t_vars *varsp, t_param *paramp)
{
	static char		**map;
	static t_imgs	*imgs;
	static t_vars	*vars;
	static t_param	*param;

	if (imgsp)
		imgs = imgsp;
	else if (varsp)
		vars = varsp;
	else if (paramp)
		param = paramp;
	else if (mapp)
		map = mapp;
	else if (!mapp && !imgsp && !varsp && !paramp)
	{
		free_param(map, imgs, vars, param);
		return (0);
	}
	return (1);
}

void	free_all(void)
{
	vars_storage(NULL, NULL, NULL, NULL);
}

int	close_window(void)
{
	free_all();
	exit(EXIT_SUCCESS);
}
