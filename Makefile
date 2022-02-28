NAME = so_long

SRC =	main.c ber_to_line.c open_imgs.c\
		move_player.c draw_map.c hook.c\
		check_input.c check_input2.c vars.c\
		free_exit.c free_mlx.c
SRCDIR = ./srcs
SRCS	=	$(addprefix $(SRCDIR)/, $(SRC))
OBJS	=	$(SRCS:%.c=%.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = ./libft
LIBFT = ft
MLXDIR	=	./minilibx-linux
MLX = mlx
INCLUDE = -I./includes -I$(LIBFTDIR) -I$(MLXDIR)

LFLAG = -L$(LIBFTDIR) -l$(LIBFT) -L$(MLXDIR) -l$(MLX) -lXext -lX11 -lm

.c.o :
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJS)
	make -C $(MLXDIR)
	make bonus -C ./libft
	$(CC) $(FLAGS) $(OBJS) $(INCLUDE) $(LFLAG) -o $(NAME)

all : $(NAME)

clean :
	make clean -C ./libft
	make clean -C $(MLXDIR)
	rm -rf $(OBJS)

fclean : clean
	make fclean -C ./libft
	make clean -C $(MLXDIR)
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re .c.o
