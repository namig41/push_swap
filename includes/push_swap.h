/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:01:58 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/02/26 19:09:46 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "vector.h"
# define TRUE 1
# define FALSE 0

typedef t_vector    t_stack;

int                 stack_is_sorted(t_stack *stack);
void                stack_push(t_stack *stack, void *data);
void                stack_swap(t_stack *stack_a, t_stack *stack_b);
void                stack_rotate(t_stack *stack_a, t_stack *stack_b);
void                stack_reverse(t_stack *stack_a, t_stack *stack_b);

# endif
