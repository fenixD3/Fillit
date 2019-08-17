# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylila <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/11 03:21:36 by ylila             #+#    #+#              #
#    Updated: 2019/08/17 21:15:43 by mdeanne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIB_NAME = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror

SRC_PATH = ./
HEAD_PATH = ./
LIB_PATH = ./libft/

SRC_FILES = bad_options.c dance_cage.c dance_create.c filling_list.c \
	free_funcs.c free_manager.c knuth_solver.c main.c \
	mkfig_arr.c move_to_zero.c validation.c

SRCS = $(addprefix $(SRC_PATH),$(SRC_FILES))

OBJS = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(LIB_NAME) $(OBJS)
	@gcc -o $(NAME) $(OBJS) -L$(LIB_PATH) -lft

$(OBJS):
	@gcc -c $(SRCS) $(FLAGS) -I$(HEAD_PATH) -I$(LIB_PATH)

$(LIB_NAME):
	@make -C $(LIB_PATH) re

clean:
	@rm -f $(OBJS)
	@make -C $(LIB_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean

re: fclean all
