# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/28 19:05:42 by matoledo          #+#    #+#              #
#    Updated: 2026/01/28 19:10:26 by matoledo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = g++

#-Wall -Wextra -Werror
CFLAGS = -Wall -Wextra -Werror

NAME = megaphone

SRCS= megaphone.cpp

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