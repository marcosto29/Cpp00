# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/28 19:11:58 by matoledo          #+#    #+#              #
#    Updated: 2026/04/28 20:58:59 by matoledo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = g++

#-Wall -Wextra -Werror
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = PhoneBook

SRCS= PhoneBook.cpp main.cpp Contact.cpp

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