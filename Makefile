NAME = cub3D

CC = cc

CFLAG = -Wall -Wextra -Werror

HEADERS = ./header

SRCS = srcs/cub3d.c srcs/exec/move.c srcs/exec/init.c srcs/exec/draw.c srcs/exec/clac.c srcs/exec/minimap.c srcs/exec/utils.c srcs/exec/exec.c\
	srcs/parse/save_map.c srcs/parse/util.c srcs/parse/ft_split.c srcs/parse/split_for_map.c srcs/parse/save_num.c\
	srcs/parse/set_map.c srcs/parse/error.c srcs/parse/white_split.c srcs/parse/check_map.c\
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\

OBJS = $(SRCS:.c=.o)

MLX_DIR = ./minilibx_opengl_20191021

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(MLX_DIR)
	$(CC) $(CFLAG) $(OBJS) $(MLX_DIR)/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -I$(MLX_DIR) -I $(HEADERS) -c $< -o $@ 

clean:
	make clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re 
