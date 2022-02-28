#include"so_long.h"

static void	get_coordinates_after_move(t_direction d, size_t *dx, size_t *dy)
{
	if (d == UP)
		(*dy)--;
	else if (d == DOWN)
		(*dy)++;
	else if (d == LEFT)
		(*dx)--;
	else if (d == RIGHT)
		(*dx)++;
}

static void	print_movement_count(int *mc)
{
	if (*mc < INT_MAX)
	{
		ft_putstr_fd("Movement count : ", 1);
		ft_putnbr_fd(++(*mc), 1);
		write(1, "\n", 1);
	}
	else
		error_exit(OF_ERR);
}

int	is_passable(t_param *param, t_direction d)
{
	size_t	px;
	size_t	py;
	char	**map;

	px = param->player_x;
	py = param->player_y;
	map = param->vars->map;
	if (d == UP && py > 1)
		py -= 1;
	else if (d == DOWN && py < param->vars->y_max - 1)
		py += 1;
	else if (d == LEFT && px > 1)
		px -= 1;
	else if (d == RIGHT && px < param->vars->x_max - 1)
		px += 1;
	else
		return (0);
	if (map[py][px] != WALL)
		return (1);
	return (0);
}

void	replace_img(t_param *param, t_direction d)
{
	size_t	dx;
	size_t	dy;

	dx = param->player_x;
	dy = param->player_y;
	get_coordinates_after_move(d, &dx, &dy);
	if (param->on_goal)
	{
		param->vars->map[param->player_y][param->player_x] = GOAL;
		param->on_goal = 0;
	}
	else
		param->vars->map[param->player_y][param->player_x] = TILE;
	put_mapchip(param, param->player_y, param->player_x);
	if (param->vars->map[dy][dx] == ITEM)
		param->gotcha--;
	else if (param->vars->map[dy][dx] == GOAL)
		param->on_goal = 1;
	param->vars->map[dy][dx] = PLAYER;
	put_mapchip(param, dy, dx);
	param->player_x = dx;
	param->player_y = dy;
	print_movement_count(&(param->m_count));
}
