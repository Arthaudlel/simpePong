CC		=	g++

RM		=	rm -rf

CPPFLAGS	=	-g3 -Wall -Werror -Wextra -I./inc -lsfml-graphics -lsfml-window -lsfml-system

S_PATH		=	srcs/

SRCS		=	$(S_PATH)main.cpp	\
			$(S_PATH)Game.cpp	\
			$(S_PATH)Ball.cpp	\
			$(S_PATH)Paddle.cpp	\
			$(S_PATH)Input.cpp
OBJS		=	$(SRCS:.cpp=.o)

NAME		=	pong

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
