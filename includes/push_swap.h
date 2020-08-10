/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:01:58 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/03/16 10:36:41 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "stack.h"
# include "get_next_line.h"

# define PA "pa"
# define PB "pb"

# define SS "ss"
# define SA "sa"
# define SB "sb"

# define RR "rr"
# define RA "ra"
# define RB "rb"

# define RRR "rrr"
# define RRA "rra"
# define RRB "rrb"

# define ERR_PR "Error\n"
# define NO_PR 0
# define OK "OK"
# define KO "KO"

# define A		0
# define B		1
# define OPT	2
# define TOTAL	3

/*
** --------------------------- FUNCTIONS --------------------------------
** --------------------------- PUSH SWAP --------------------------------
*/

void				stack_sort(t_stack *a, t_stack *b);
void				stack_sort_part_1(t_stack *a, t_stack *b, t_vector *vector);
void				stack_sort_part_2(t_stack *a, t_stack *b, t_vector *vector);

/*
** --------------------------- OPERATIONS -----------------------------
*/

void				ph(t_stack *a, t_stack *b, char *oper);
void				ss(t_stack *a, t_stack *b, char *oper);
void				rr(t_stack *a, t_stack *b, char *oper);
void				rrr(t_stack *a, t_stack *b, char *oper);

/*
** --------------------------- VALIDATION -----------------------------
*/

void				valid_line(t_stack *a, t_stack *b, char *line);
void				parse_arg(t_stack *a, t_stack *b, int argc, char *argv[]);

/*
** --------------------------- ERROR ------------------------------------
*/

void				print_error(t_stack *a, t_stack *b);

/*
** --------------------------- INFORMATION -----------------------------
*/

int					get_opt_elem(t_stack *a, t_stack *b, int c, t_vector *v);
int					get_true_position(t_vector *vector, int elem);
int					get_opt_index(t_stack *stack, int elem);
int					get_index(t_stack *a, int elem);

#endif
