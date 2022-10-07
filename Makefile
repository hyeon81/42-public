NAME = pipex

CC = cc

CFLAG = -Wall -Wextra -Werror -fsanitize=

SRCS = ./pipex.c ./pipex_util.c ./ft_split.c

HEADERS = pipex.h

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(CFLAG) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -I $(HEADERS) -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
