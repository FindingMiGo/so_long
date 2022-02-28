#include "so_long.h"

void	open_imgs(void *mlx, t_imgs **imgs)
{
	int	width;
	int	height;

	*imgs = (t_imgs *)ft_calloc(1, sizeof(t_imgs));
	vars_storage(NULL, *imgs, NULL, NULL);
	(*imgs)->wall = mlx_xpm_file_to_image(mlx, IMG_WALL, &width, &height);
	(*imgs)->player = mlx_xpm_file_to_image(mlx, IMG_PLAYER, &width, &height);
	(*imgs)->tile = mlx_xpm_file_to_image(mlx, IMG_TILE, &width, &height);
	(*imgs)->item = mlx_xpm_file_to_image(mlx, IMG_ITEM, &width, &height);
	(*imgs)->goal = mlx_xpm_file_to_image(mlx, IMG_GOAL, &width, &height);
	if (!((*imgs)->wall) || !((*imgs)->player)
		|| !((*imgs)->tile) || !((*imgs)->item) || !((*imgs)->goal))
		error_exit(OPENIMG_ERR);
}
