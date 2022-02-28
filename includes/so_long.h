#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>

# define IMG_PLAYER "imgs/player.xpm"
# define IMG_WALL "imgs/wall.xpm"
# define IMG_TILE "imgs/tile.xpm"
# define IMG_ITEM "imgs/item.xpm"
# define IMG_GOAL "imgs/goal.xpm"

# define PIXSIZ 64

# define KEY_ESC 0xff1b
# define KEY_W 0x0077
# define KEY_A 0x0061
# define KEY_S 0x0073
# define KEY_D 0x0064

typedef enum e_direction{
	UP,
	DOWN,
	RIGHT,
	LEFT
}	t_direction;

typedef enum e_chiptype{
	WALL = '1',
	TILE = '0',
	PLAYER = 'P',
	ITEM = 'C',
	GOAL = 'E'
}	t_chiptype;

typedef struct s_imgs {
	void	*player;
	void	*wall;
	void	*tile;
	void	*item;
	void	*goal;
}				t_imgs;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	size_t	x_max;
	size_t	y_max;
}				t_vars;

typedef struct s_param {
	size_t	player_x;
	size_t	player_y;
	int		on_goal;
	int		m_count;
	size_t	gotcha;
	t_imgs	*imgs;
	t_vars	*vars;
}				t_param;

typedef enum e_errtype {
	OPENIMG_ERR,
	FNAME_ERR,
	ARG_ERR,
	MAP_ERR,
	CHR_ERR,
	MLC_ERR,
	OPENFILE_ERR,
	EMPTY_ERR,
	WALL_ERR,
	OVER_SIZE_ERR,
	SHAPE_ERR,
	MLX_ERR,
	OF_ERR
}				t_errtype;

# define TITLE "so_long"

# define OPENIMG_ERR_MSG "Failed to open the image.\n"
# define FNAME_ERR_MSG "The file name should end with \".ber\".\n"
# define ARG_ERR_MSG "Please enter only one file.\n"
# define MAP_ERR_MSG "Invalid number of elements.\n"
# define CHR_ERR_MSG "Invalid characters in input.\n"
# define MLC_ERR_MSG "Failed to allocate memory.\n"
# define OPENFILE_ERR_MSG "Failed to open or close the file.\n"
# define EMPTY_ERR_MSG "Invalid file.\n"
# define WALL_ERR_MSG "The map must be surrounded by walls.\n"
# define OVER_SIZE_MSG "A truly marvelous map, \
which this margin is too narrow to contain.\n"
# define SHAPE_ERR_MSG "The map must be rectangular.\n"
# define MLX_ERR_MSG "Failed to initialize the window.\n"
# define OF_ERR_MSG "The number of moves has overflowed.\n"

// main.c
size_t	get_rowsize(char **map);

// ber_to_line.c
char	*ber_to_line(char **av);

// check_input.c
int		validate_map(char *mapline, t_param *param);
int		is_rectangle(char **map, t_vars *vars);

// check_input2.c
int		is_validchr(char *line);
int		is_valid_filename(char **input);
int		is_blankline_insertion(char *line);
int		check_arg(int ac, char **av);

// draw_map.c
void	put_mapchip(t_param *param, size_t i, size_t j);
int		draw_allfloor(t_param *param);

// free_exit.c
void	error_exit(t_errtype type);

// free_mlx.c
void	free_imgs(void *mlx, t_imgs *imgs);
void	free_mlx(void *mlx);

// hook.c
int		key_hook(int keycode, t_param *param);

// move_player.c
int		is_passable(t_param *param, t_direction d);
void	replace_img(t_param *param, t_direction d);

// open_imgs.c
void	open_imgs(void *mlx, t_imgs **imgs);

// vars.c
int		vars_storage(char **mapp, t_imgs *imgsp,
			t_vars *varsp, t_param *paramp);
void	free_map(char **lines);
void	free_all(void);
int		close_window(void);

#endif
