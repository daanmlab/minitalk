# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 20:51:27 by dabalm            #+#    #+#              #
#    Updated: 2023/11/14 21:05:19 by dabalm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

SRC_CLIENT = client.c
SRC_SERVER = server.c

LIBFT = libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

all : $(NAME_CLIENT) $(NAME_SERVER)

bonus : $(NAME_BONUS)

$(NAME_CLIENT): $(SRC_CLIENT)
	@$(MAKE) -sC ./libft
	@echo "Creating $(NAME_CLIENT)"
	@$(CC) $(CFLAGS) $(SRC_CLIENT) $(LIBFT) -o $(NAME_CLIENT)
	
$(NAME_SERVER): $(SRC_SERVER)
	@$(MAKE) -sC ./libft
	@echo "Creating $(NAME_SERVER)"
	@$(CC) $(CFLAGS) $(SRC_SERVER) $(LIBFT) -o $(NAME_SERVER)

clean :
	$(MAKE) clean -sC ./libft

fclean :
	@$(MAKE) fclean -sC ./libft
	@echo "Cleaning minitalk"
	@rm -rf $(NAME_CLIENT)
	@rm -rf $(NAME_SERVER)

fnorm :
	@$(MAKE) -s fclean
	@python3 -m c_formatter_42 $(SRC_CLIENT) $(SRC_SERVER) */*.h
	norminette $(SRC_CLIENT) $(SRC_SERVER) */*.h

re : fclean all

.PHONY : clean fclean fnorm re all bonus%         