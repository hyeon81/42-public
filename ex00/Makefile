CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = megaphone

SCRS = megaphone.cpp

OBJS = $(SRCS:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -c $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean
	$(NAME) all

.PHONY : all clean fclean re

