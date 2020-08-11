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
DIR_OBJ			= ./obj/

SRC_PUSH_SWAP 	= $(addprefix $(DIR_SRC), $(addsuffix .c, $(FILE_PUSH_SWAP)))
OBJ_PUSH_SWAP 	= $(addprefix $(DIR_OBJ), $(addsuffix .o, $(FILE_PUSH_SWAP)))

SRC_CHECKER 	= $(addprefix $(DIR_SRC), $(addsuffix .c, $(FILE_CHECKER)))
OBJ_CHECKER 	= $(addprefix $(DIR_OBJ), $(addsuffix .o, $(FILE_CHECKER)))

CC 	   			= gcc
PUSH_SWAP 		= push_swap
CHECKER 		= checker
#CFLAGS 	   		= -Wall -Werror -Wextra -O2 -I$(DIR_INC) -I$(DIR_LIB)$(DIR_INC)
CFLAGS 	   		=  -g -O2 -I$(DIR_INC) -I$(DIR_LIB)$(DIR_INC)

all: push_swap checker

lib:
	@make -C $(DIR_LIB) > /dev/null

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

checker: $(OBJ_CHECKER) lib 
	@$(CC) $(CFLAGS) -o $(CHECKER) $(OBJ_CHECKER) $(DIR_LIB)libft.a

push_swap: $(OBJ_PUSH_SWAP) lib 
	@$(CC) $(CFLAGS) -o $(PUSH_SWAP) $(OBJ_PUSH_SWAP) $(DIR_LIB)libft.a

$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
 
clean:
	@make clean -C $(DIR_LIB)
	@rm -rf $(DIR_OBJ)

fclean: clean
	@make fclean -C $(DIR_LIB)
	@rm -f $(PUSH_SWAP)
	@rm -f $(CHECKER)

re: fclean all

compile: re
	@clear
	./$(PUSH_SWAP)

.PHONY: all clean fclean re compile checker push_swap
