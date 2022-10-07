NAME = pipex

CC = gcc

CFLAG = -Wall -Wextra -Werror 

SRCS = pipex.c pipex_util.c ft_split.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(CFLAG) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
