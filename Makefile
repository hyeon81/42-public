NAME = push_swap

CC = cc

CFLAG = -Wall -Wextra -Werror

SRCS = ft_p.c ft_r.c ft_rr.c ft_s.c sort_under_five.c sort_over_five.c\
ft_split.c init.c push_pop.c main.c utils.c

HEADERS = push_swap.h

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
