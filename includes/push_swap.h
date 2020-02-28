/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:01:58 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/02/28 19:41:51 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "stack.h"

int                 stack_is_sorted(t_stack *stack);
void                stack_quick_sort(t_stack *stack_a, t_stack *stack_b);
void                stack_print(t_stack *stack);

void                ph(t_stack *a, t_stack *b);
void                ss(t_stack *a, t_stack *b);
void                rr(t_stack *a, t_stack *b);
void                rrr(t_stack *a, t_stack *b);



# endif
