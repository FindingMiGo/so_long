#include "so_long.h"

void	put_mapchip(t_param *param, size_t i, size_t j)
{
	char	**map;
	void	*mlx;
	void	*win;
	t_imgs	*imgs;

	win = param->vars->win;
	mlx = param->vars->mlx;
	map = param->vars->map;
	imgs = param->imgs;
	if (map[i][j] == WALL)
		mlx_put_image_to_window(mlx, win, imgs->wall, j * PIXSIZ, i * PIXSIZ);
	else if (map[i][j] == TILE)
		mlx_put_image_to_window(mlx, win, imgs->tile, j * PIXSIZ, i * PIXSIZ);
	else if (map[i][j] == PLAYER)
		mlx_put_image_to_window(mlx, win, imgs->player, j * PIXSIZ, i * PIXSIZ);
	else if (map[i][j] == GOAL)
		mlx_put_image_to_window(mlx, win, imgs->goal, j * PIXSIZ, i * PIXSIZ);
	else if (map[i][j] == ITEM)
		mlx_put_image_to_window(mlx, win, imgs->item, j * PIXSIZ, i * PIXSIZ);
}

int	draw_allfloor(t_param *param)
{
	size_t	i;
	size_t	j;
	char	**map;

	i = 0;
	j = 0;
	map = param->vars->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			put_mapchip(param, i, j);
			if (map[i][j] == PLAYER)
			{
				param->player_x = j;
				param->player_y = i;
			}
			j++;
		}
		i++;
	}
	return (0);
}
