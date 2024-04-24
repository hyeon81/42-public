NAME = philo

CC = cc

CFLAG = -Wall -Wextra -Werror #-g -fsanitize=thread

SRCS = init.c run_philo.c utils.c check_die.c main.c

HEADERS = philo.h

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) -pthread -o $(CFLAG) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -pthread -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

