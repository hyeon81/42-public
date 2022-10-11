NAME = pipex

CC = cc

CFLAG = -Wall -Wextra -Werror -g3

SRCS = ./pipex.c ./pipex_util.c ./pipex_argv.c ./ft_split.c

BONUS = ./pipex_bonus.c ./pipex_util.c ./pipex_argv.c ./ft_split.c

HEADERS = pipex.h

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = ${BONUS_OBJS}
else
	OBJ_FILES = ${OBJS}
endif

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	$(CC) -o $(CFLAG) $(OBJ_FILES) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -I $(HEADERS) -c $< -o $@ 

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

bonus: 
	make WITH_BONUS=1 all

.PHONY:	all clean fclean bonus re
