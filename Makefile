# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: asaba <marvin@le-101.fr>                   +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/02 17:01:24 by asaba        #+#   ##    ##    #+#        #
#    Updated: 2018/10/31 14:00:35 by asaba       ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fillit

CC = gcc

SRC = srcs/fill_checker.c srcs/fill_reader.c srcs/fillit.c srcs/fill_algo.c
SRC += srcs/error.c srcs/fill_position.c srcs/fill_checkfit.c 
SRC += srcs/fill_utility.c

LIBS = libft/libft.a

OBJ = $(SRC:.c=.o)

CFLAGS = -Werror -Wextra -Wall -Iincludes

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft	
	@$(CC) -o $@ $(LIBS) $?
clean:
	@rm -f $(OBJ)
	@cd libft && $(MAKE) clean

fclean: clean
	@rm -f $(NAME)
	@cd libft && $(MAKE) fclean

re: fclean all
