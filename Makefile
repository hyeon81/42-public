NAME = so_long

CC = cc

CFLAG = -Wall -Wextra -Werror #-g3 -fsanitize=address

HEADERS = ./header

SRCS = srcs/so_long.c srcs/so_long_init.c srcs/get_next_line.c srcs/get_next_line_utils.c srcs/so_long_exit.c srcs/check_suffix.c

OBJS = $(SRCS:.c=.o)

MLX_DIR = ./minilibx_opengl_20191021

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(CFLAG) $(OBJS) -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -I $(HEADERS) -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
