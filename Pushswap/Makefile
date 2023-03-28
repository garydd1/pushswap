# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 15:56:11 by dgarizad          #+#    #+#              #
#    Updated: 2023/03/26 22:06:37 by dgarizad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = pushswap.c checker.c merge.c operations.c utils.c stackbops.c stackaops.c
HEADER = pushswap.h

OBJS = $(SRC:.c=.o)
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
  
all: $(NAME)

%.o: %.c
	@$(CC) -c $< -o $@ #place flags!

$(NAME): $(OBJS) $(HEADER)
	@$(CC) $(OBJS) -o $(NAME) #REMEMBER TO PLACE FLAGS
clean :
	rm  -f *.o
fclean: clean
		rm -f $(NAME)
re: fclean all
.PHONY : all clean fclean re 
