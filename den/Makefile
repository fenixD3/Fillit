# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylila <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 12:26:13 by ylila             #+#    #+#              #
<<<<<<< HEAD:den/fillit/Makefile
#    Updated: 2019/08/10 23:09:54 by ylila            ###   ########.fr        #
=======
#    Updated: 2019/08/10 22:24:32 by ylila            ###   ########.fr        #
>>>>>>> eg:fillit/Makefile
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIB_NAME = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror

SRC_PATH = ./
HEAD_PATH = ./
LIB_PATH = ./libft/

SRC_FILES = *.c
SRCS = $(addprefix $(SRC_PATH), $(SRC_FILES))

<<<<<<< HEAD:den/fillit/Makefile
OBJS = $(SRC_FILES:.c=.o)
=======
<<<<<<< HEAD
OBJS = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(LIB_NAME) $(OBJS)
	@gcc -o $(NAME) $(OBJS) -L$(LIB_PATH) -lft

$(OBJS):
	@gcc -c $(SRCS) $(FLAGS) -I$(HEAD_PATH) -I$(LIB_PATH)

$(LIB_NAME):
=======
HEAD_FILES = *.h
HDRS = $(addprefix $(HEAD_PATH), $(HEAD_FILES))

OBJS = $(SRC_FILES:.c=.O)
>>>>>>> eg:fillit/Makefile

all: $(NAME)

$(NAME): $(LIB_NAME) $(OBJS)
	@gcc -o $(NAME) $(OBJS) -L$(LIB_PATH) -lft

<<<<<<< HEAD:den/fillit/Makefile
$(OBJS):
	@gcc -c $(SRCS) $(FLAGS) -I$(HEAD_PATH) -I$(LIB_PATH)

$(LIB_NAME):
=======
lib:
>>>>>>> master
>>>>>>> eg:fillit/Makefile
	@make -C $(LIB_PATH) re

clean:
	@rm -f $(OBJS)
	@make -C $(LIB_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean

re: fclean all
