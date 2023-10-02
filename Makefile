NAME = ircserv

CPP = c++

CFLAGS = #-Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Server.cpp Client.cpp Message.cpp Channel.cpp ChannelUtils.cpp \
ClientUtils.cpp Commands.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re

