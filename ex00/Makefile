M_NAME = Animal

WRONG_NAME = WrongAnimal

CPP = c++

CFLAGS = -Wall -Wextra -Werror 

SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp

WRONG_SRCS = main_wrong.cpp WrongAnimal.cpp WrongCat.cpp

OBJS = $(SRCS:.cpp=.o)

WRONG_OBJS = $(WRONG_SRCS:.cpp=.o)

ifdef WITH_WRONG
		OBJ_FILES = ${WRONG_OBJS}
		NAME = ${WRONG_NAME}
else
		OBJ_FILES = ${OBJS}
		NAME = ${M_NAME}
endif

all: $(NAME)

$(NAME) : $(OBJ_FILES)
	$(CPP) -o $(CFLAGS) $(OBJ_FILES) -o $(NAME)

%.o : %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJS) $(WRONG_OBJS)

fclean : clean
	rm -f $(M_NAME) $(WRONG_NAME)

re: fclean all

wrong: 
	make WITH_WRONG=1 all

.PHONY:	all clean fclean wrong re

