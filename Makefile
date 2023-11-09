# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 12:29:54 by dabalm            #+#    #+#              #
#    Updated: 2023/11/02 13:06:56 by dabalm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAIN_CLIENT=./client.c
MAIN_SERVER=./server.c
NAME_CLIENT=client
NAME_SERVER=server

LIBFT = libft/libft.a

CC = CC
CFLAGS = -Wall -Wextra -Werror -g


.PHONY : server client

$(NAME_CLIENT) : $(MAIN_CLIENT)
	$(MAKE) -sC ./libft
	@$(CC) $(CFLAGS) $(MAIN_CLIENT) $(LIBFT) -o $(NAME_CLIENT)
	
$(NAME_SERVER) : $(MAIN_SERVER)
	$(MAKE) -sC ./libft
	@$(CC) $(CFLAGS) $(MAIN_SERVER) $(LIBFT) -o $(NAME_SERVER)

# server : $(NAME_SERVER)

# client : $(NAME_CLIENT)

all : $(NAME_SERVER) $(NAME_CLIENT)

fnorm :
	@$(MAKE) -s fclean
	@python3 -m c_formatter_42 $(SRCS) $(SRCS_BONUS) */*.h
	norminette $(SRCS) $(SRCS_BONUS) */*.h

