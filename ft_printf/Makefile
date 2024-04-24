NAME = libftprintf.a

CC = gcc

CFLAG = -Wall -Wextra -Werror

SRCS = ft_print_hex.c \
ft_print_ptr.c \
ft_print_ui.c \
ft_printf.c \
ft_putchar.c \
ft_putnbr.c \
ft_putstr.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
