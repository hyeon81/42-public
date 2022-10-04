NAME = pipex

CC = cc

CFLAG = -Wall -Wextra -Werror

SRCS = 

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
