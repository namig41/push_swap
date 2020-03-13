/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:01:58 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/03/02 14:14:16 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "stack.h"

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

int                 get_median(t_vector *vector, size_t med);
void                stack_print(t_stack *stack);
int                 vector_is_sorted(t_stack *stack);
void                stack_sort(t_stack *a, t_stack *b);

void                ph(t_stack *a, t_stack *b, char *oper);
void                ss(t_stack *a, t_stack *b, char *oper);
void                rr(t_stack *a, t_stack *b, char *oper);
void                rrr(t_stack *a, t_stack *b, char *oper);

int                 g_count;

# endif
