# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+         # #                                                 +#+#+#+#+#+   +#+            # #    Created: 2020/02/27 18:15:20 by lcarmelo          #+#    #+#              #
#    Updated: 2020/02/27 18:19:57 by lcarmelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FUN_NAME = \
		push_swap \
		stack 

DIR_SRC			= ./src/
DIR_INC			= ./includes/
DIR_LIB			= ./libft/

SRC_PUSH_SWAP 	= $(addprefix $(DIR_SRC), $(addsuffix .c, $(FUN_NAME)))
OBJ_PUSH_SWAP 	= $(addsuffix .o, $(FUN_NAME))

CC 	   			= gcc
NAME 			= push_swap
CFLAGS 	   		= -Wall -Werror -Wextra -O2 -I$(DIR_INC) -I$(DIR_LIB)$(DIR_INC)
#CFLAGS 	   		=  -O2 libft.a -I$(DIR_INC) -I$(DIR_LIB)$(DIR_INC)

all: $(NAME)

obj:
	@$(CC) $(CFLAGS) -c $(SRC_PUSH_SWAP)

lib:
	@make -C $(DIR_LIB)
	@cp libft/libft.a ./

$(NAME): lib obj  
	@$(CC) $(CFLAGS) libft.a $(OBJ_PUSH_SWAP) -o $(NAME)

clean:
	@make clean -C $(DIR_LIB)
	@rm -f $(OBJ_PUSH_SWAP)
	@rm -f libft.a

fclean: clean
	@make fclean -C $(DIR_LIB)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
