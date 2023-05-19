NAME = cub3D

CC = cc

CFLAG = #-g -fsanitize=address #-Wall -Wextra -Werror 

HEADERS = ./header

SRCS = srcs/cub3d.c srcs/move.c srcs/init.c srcs/draw.c srcs/clac.c srcs/minimap.c srcs/utils.c srcs/exec.c\
	srcs/init_map.c srcs/util.c srcs/ft_split.c srcs/split_for_map.c  srcs/ft_atoi.c\
	srcs/path_color.c srcs/error.c\
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\

OBJS = $(SRCS:.c=.o)

MLX_DIR = ./minilibx_opengl_20191021

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# $(NAME) : $(OBJS)
# 	$(CC) $(CFLAG) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
# # $(CC) $(CFLAG) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
#  $(CC) $(CFLAG) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -Imlx -I $(HEADERS) -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re 
