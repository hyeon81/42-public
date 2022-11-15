M_NAME = push_swap

BONUS_NAME = checker

CC = cc

CFLAG = -Wall -Wextra -Werror

SRCS = ft_p.c ft_r.c ft_rr.c ft_s.c sort_under_five.c sort_over_five.c\
ft_split.c init.c push_pop.c main.c utils.c utils2.c

BONUS = ft_p.c ft_r.c ft_rr.c ft_s.c \
ft_split.c init.c push_pop.c main_bonus.c utils.c utils2.c \
get_next_line_bonus.c get_next_line_utils_bonus.c

HEADERS = push_swap.h

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = ${BONUS_OBJS}
	NAME = ${BONUS_NAME}
else
	OBJ_FILES = ${OBJS}
	NAME = ${M_NAME}
endif

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	$(CC) -o $(CFLAG) $(OBJ_FILES) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@ 

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(M_NAME) $(BONUS_NAME)

re: fclean all

bonus: 
	make WITH_BONUS=1 all

.PHONY:	all clean fclean bonus re