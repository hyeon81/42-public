NAME = megaphone

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = ./megaphone.cpp

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

bonus: 
	make all

.PHONY:	all clean fclean bonus re
