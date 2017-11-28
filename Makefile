# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tperraut <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/06 15:54:33 by tperraut          #+#    #+#              #
#*   Updated: 2016/07/06 14:08:25 by tperraut         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

##########
# TARGET #
##########

NAME = libftprintf.a

############
# COMPILER #
############

CC = clang
CFLAGS = -O3 -Werror -Wall -Wextra

#######
# LIB #
#######

LIB = ar rc

##########
# HEADER #
##########

INC_DIR = ./include/
INC_NAME = \
		libftprintf.h
INCLUDE = $(addprefix $(INC_DIR), $(INC_NAME))
INC = -I $(INC_DIR)

##########
# SOURCE #
##########

SRC_DIR = ./src/
SRC_NAME = \
	buffer.c \
	specs.c \
	core.c \
	flags.c \
	check_flags.c \
	modifier.c \
	width.c \
	preci.c \
	type.c \
	ft_printf.c \
	switch_mode.c \
	print_char.c \
	print_int.c \
	print_short.c \
	print_long.c \
	print_llong.c \
	print_intmax_t.c \
	print_size_t.c \
	print_p.c \
	print_c.c \
	print_wc.c \
	print_s.c \
	print_ws.c
SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))

##########
# OBJECT #
##########

OBJ_DIR = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))

#########
# RULES #
#########

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(LIB) $@ $(OBJ)
	ranlib $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ -c $< $(INC)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

norme: $(SRC) $(INCLUDE)
	norminette $^

test: all
	$(CC) -o test main.c $(INC) -L ./ -lftprintf

.PHONY: all clean fclean re norme test
