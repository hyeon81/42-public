NAME = cub3D

CC = cc

CFLAG =  -g -fsanitize=address -Wall -Wextra -Werror

HEADERS = ./header

SRCS = srcs/cub3d.c srcs/keyevent.c srcs/init.c srcs/draw.c srcs/clac.c 

OBJS = $(SRCS:.c=.o)

MLX_DIR = ./minilibx_opengl_20191021

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# $(NAME) : $(OBJS)
# 	$(CC) $(CFLAG) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -Imlx -I $(HEADERS) -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re 
