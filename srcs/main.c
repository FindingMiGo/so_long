#include "so_long.h"

size_t	get_rowsize(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static void	init_window(t_vars *vars)
{
	int	win_x;
	int	win_y;

	win_x = 0;
	win_y = 0;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		error_exit(MLX_ERR);
	vars->win = mlx_new_window(vars->mlx, (vars->x_max + 1) * PIXSIZ,
			(vars->y_max + 1) * PIXSIZ, TITLE);
	if (!vars->win)
		error_exit(MLX_ERR);
	mlx_get_screen_size(vars->mlx, &win_x, &win_y);
	if (win_x < ((vars->x_max + 1) * PIXSIZ)
		|| win_y < ((vars->y_max + 1) * PIXSIZ))
		error_exit(OVER_SIZE_ERR);
}

static void	set_map(char **av, char **line, t_vars **vars, t_param *param)
{
	char	**map;

	map = NULL;
	*vars = (t_vars *)ft_calloc(1, sizeof(t_vars));
	if (!vars_storage(NULL, NULL, *vars, NULL))
		error_exit(MLC_ERR);
	*line = ber_to_line(av);
	validate_map(*line, param);
	map = ft_split(*line, '\n');
	free(*line);
	if (!vars_storage(map, NULL, NULL, NULL))
		error_exit(MLC_ERR);
	if (!is_rectangle(map, param->vars))
		error_exit(WALL_ERR);
	(*vars)->map = map;
	(*vars)->x_max = ft_strlen(map[0]) - 1;
	(*vars)->y_max = get_rowsize(map) - 1;
}

static void	loop_start(t_param *param)
{
	mlx_key_hook(param->vars->win, key_hook, param);
	mlx_hook(param->vars->win, 12, 1L << 15, draw_allfloor, param);
	mlx_hook(param->vars->win, 17, 0, close_window, NULL);
	mlx_loop(param->vars->mlx);
}

int	main(int argc, char *argv[])
{
	t_param	*param;
	char	*line;

	check_arg(argc - 1, argv + 1);
	param = (t_param *)ft_calloc(1, sizeof(t_param));
	if (!vars_storage(NULL, NULL, NULL, param))
		error_exit(MLC_ERR);
	set_map(argv + 1, &line, &param->vars, param);
	init_window(param->vars);
	open_imgs(param->vars->mlx, &param->imgs);
	draw_allfloor(param);
	loop_start(param);
	return (0);
}
