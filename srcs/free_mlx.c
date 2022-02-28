#include "so_long.h"

void	free_imgs(void *mlx, t_imgs *imgs)
{
	if (imgs->goal)
		mlx_destroy_image(mlx, imgs->goal);
	if (imgs->player)
		mlx_destroy_image(mlx, imgs->player);
	if (imgs->tile)
		mlx_destroy_image(mlx, imgs->tile);
	if (imgs->item)
		mlx_destroy_image(mlx, imgs->item);
	if (imgs->wall)
		mlx_destroy_image(mlx, imgs->wall);
	free(imgs);
}

void	free_mlx(void *mlx)
{
	mlx_destroy_display(mlx);
	free(mlx);
}
