NAME = ircserv

CPP = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Server.cpp Client.cpp Channel.cpp ChannelUtils.cpp ClientUtils.cpp SendUtils.cpp\
./cmd/nick.cpp ./cmd/user.cpp ./cmd/join.cpp ./cmd/part.cpp ./cmd/topic.cpp\
./cmd/invite.cpp ./cmd/kick.cpp ./cmd/mode.cpp ./cmd/privmsg.cpp ./cmd/pass.cpp\
./cmd/ping.cpp ./cmd/who.cpp ./cmd/whois.cpp ./cmd/quit.cpp 

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

