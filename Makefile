NAME = push_swap

CC = cc

CFLAG = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_isdigit.c ft_lstnew.c ft_memset.c ft_p.c ft_putstr.c ft_r.c ft_rr.c ft_s.c \
ft_split.c init.c push_pop.c push_swap.c quick_sort.c valid.c

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
