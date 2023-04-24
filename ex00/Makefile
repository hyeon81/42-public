NAME = Animal

CPP = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp

OBJS = $(SRCS:.cpp=.o)

HEADER = Animal.hpp 

all: $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CPP) $(CFLAGS) -I $(HEADER) -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re

