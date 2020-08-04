# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/13 19:35:02 by lcarmelo          #+#    #+#              #
#    Updated: 2020/03/14 16:53:49 by lcarmelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE_GENERAL = \
			parse_arg \
			stack_operation

FILE_PUSH_SWAP = \
			push_swap \
			sort \
			sort_part_1 \
			sort_part_2 \
			information \
			$(FILE_GENERAL)

FILE_CHECKER = \
			checker \
			$(FILE_GENERAL)

DIR_SRC			= ./src/
DIR_INC			= ./includes/
DIR_LIB			= ./libft/

SRC_PUSH_SWAP 	= $(addprefix $(DIR_SRC), $(addsuffix .c, $(FILE_PUSH_SWAP)))
OBJ_PUSH_SWAP 	= $(addsuffix .o, $(FILE_PUSH_SWAP))

SRC_CHECKER 	= $(addprefix $(DIR_SRC), $(addsuffix .c, $(FILE_CHECKER)))
OBJ_CHECKER 	= $(addsuffix .o, $(FILE_CHECKER))

CC 	   			= gcc
PUSH_SWAP 		= push_swap
CHECKER 		= checker
#CFLAGS 	   		= -Wall -Werror -Wextra -O2 -I$(DIR_INC) -I$(DIR_LIB)$(DIR_INC)
CFLAGS 	   		=  -O2 -I$(DIR_INC) -I$(DIR_LIB)$(DIR_INC)

all: push_swap checker

lib:
	@make -C $(DIR_LIB)
	@cp libft/libft.a ./

obj_checker:
	@$(CC) $(CFLAGS) -c $(SRC_CHECKER)

obj_push_swap:
	@$(CC) $(CFLAGS) -c $(SRC_PUSH_SWAP)

checker: lib obj_checker
	@$(CC) $(CFLAGS) -o $(CHECKER) $(OBJ_CHECKER) libft/libft.a

push_swap: lib obj_push_swap
	@$(CC) $(CFLAGS) -o $(PUSH_SWAP) $(OBJ_PUSH_SWAP) libft/libft.a
 
clean:
	@make clean -C $(DIR_LIB)
	@rm -f $(OBJ_PUSH_SWAP)
	@rm -f $(OBJ_CHECKER)
	@rm -f libft.a

fclean: clean
	@make fclean -C $(DIR_LIB)
	@rm -f $(PUSH_SWAP)
	@rm -f $(CHECKER)

re: fclean all

compile: re
	@clear
	./$(PUSH_SWAP)

.PHONY: all clean fclean re compile
