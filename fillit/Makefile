# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylila <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 12:26:13 by ylila             #+#    #+#              #
#    Updated: 2019/08/10 06:15:53 by yas              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRCS = main.c validation.c mkfig_arr.c dance_create.c dance_cage.c \
	   filling_list.c increase_list.c increase.c knuth_solver.c \
	   bad_options.c free_funcs.c

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRCS) -I./ -I./libft/
	gcc $(FLAGS) -o $(NAME) $(OBJECTS) -L ./libft/ -lft

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
