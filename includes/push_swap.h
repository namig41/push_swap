/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:01:58 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/02/27 18:24:17 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "stack.h"

int                 stack_is_sorted(t_stack *stack);
void                stack_swap(t_stack *stack_a, t_stack *stack_b);
void                stack_rotate(t_stack *stack_a, t_stack *stack_b);
void                stack_reverse(t_stack *stack_a, t_stack *stack_b);
void                stack_quick_sort(t_stack *stack_a, t_stack *stack_b);


# endif
