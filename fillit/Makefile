# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylila <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 12:26:13 by ylila             #+#    #+#              #
#    Updated: 2019/05/12 17:39:26 by ylila            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRC_PATH = ./
HEAD_PATH = ./
LIB_PATH = ./libft/

SRC_FILES = *.c
SRCS = $(addprefix $(SRC_PATH), $(SRC_FILES))

HEAD_FILES = *.h
HDRS = $(addprefix $(HEAD_PATH), $(HEAD_FILES))

OBJS = $(SRC_FILES:.c=.O)

all: $(NAME)

$(NAME): lib
	@gcc -c $(SRCS) $(FLAGS) -I$(HEAD_PATH) -I$(LIB_PATH)
	@gcc -o $(NAME) $(OBJS) -L$(LIB_PATH) -lft

lib:
	@make -C $(LIB_PATH) re

clean:
	@rm -f $(OBJS)
	@make -C $(LIB_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean

re: fclean all
