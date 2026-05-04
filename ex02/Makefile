
CC = g++

#-Wall -Wextra -Werror
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = tests

SRCS= Account.cpp tests.cpp

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS)

%.o: %.c
	@$(CC) -c $(CFLAGS) $<

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all