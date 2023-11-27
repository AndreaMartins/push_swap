# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 09:51:33 by andmart2          #+#    #+#              #
#    Updated: 2023/11/23 17:15:21 by andmart2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror -MMD -I ./

SRC = auxiliars.c checkers.c main_push_swap.c sizes.c moves.c

OBJ = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)


all: $(NAME)

%.o: %.c Makefile
	$(CC) $(FLAGS) -c $< -o $@

-include $(DEPS)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
