#include "so_long.h"

int	key_hook(int keycode, t_param *param)
{
	if (keycode == KEY_ESC)
	{
		free_all();
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_W && is_passable(param, UP))
		replace_img(param, UP);
	else if (keycode == KEY_S && is_passable(param, DOWN))
		replace_img(param, DOWN);
	else if (keycode == KEY_A && is_passable(param, LEFT))
		replace_img(param, LEFT);
	else if (keycode == KEY_D && is_passable(param, RIGHT))
		replace_img(param, RIGHT);
	else
		return (0);
	if (param->on_goal && param->gotcha == 0)
	{
		free_all();
		exit(EXIT_SUCCESS);
	}
	return (0);
}
