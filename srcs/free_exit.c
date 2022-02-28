#include "so_long.h"

static void	alloc_error(t_errtype type)
{
	if (type == MLC_ERR)
		ft_putstr_fd(MLC_ERR_MSG, 2);
	else if (type == MLX_ERR)
		ft_putstr_fd(MLX_ERR_MSG, 2);
}

static void	invalid_map_error(t_errtype type)
{
	if (type == OVER_SIZE_ERR)
		ft_putstr_fd(OVER_SIZE_MSG, 2);
	else if (type == SHAPE_ERR)
		ft_putstr_fd(SHAPE_ERR_MSG, 2);
	else if (type == EMPTY_ERR)
		ft_putstr_fd(EMPTY_ERR_MSG, 2);
	else if (type == WALL_ERR)
		ft_putstr_fd(WALL_ERR_MSG, 2);
	else if (type == MAP_ERR)
		ft_putstr_fd(MAP_ERR_MSG, 2);
}

void	error_exit(t_errtype type)
{
	ft_putstr_fd("Error\n", 2);
	if (type == OPENIMG_ERR)
		ft_putstr_fd(OPENIMG_ERR_MSG, 2);
	else if (type == FNAME_ERR)
		ft_putstr_fd(FNAME_ERR_MSG, 2);
	else if (type == ARG_ERR)
		ft_putstr_fd(ARG_ERR_MSG, 2);
	else if (type == CHR_ERR)
		ft_putstr_fd(CHR_ERR_MSG, 2);
	else if (type == OPENFILE_ERR)
		ft_putstr_fd(OPENFILE_ERR_MSG, 2);
	else if (type == OF_ERR)
		ft_putstr_fd(OF_ERR_MSG, 2);
	else
	{
		invalid_map_error(type);
		alloc_error(type);
	}
	if (type != MLC_ERR)
		free_all();
	exit(EXIT_FAILURE);
}
