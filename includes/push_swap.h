/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:01:58 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/02/29 19:54:54 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "stack.h"

void                stack_print(t_stack *stack);
int                 stack_is_sorted(t_stack *stack);
void                sort2(t_stack *a, t_stack *b);
void                sort(t_stack *a, t_stack *b);

void                ph(t_stack *a, t_stack *b);
void                ss(t_stack *a, t_stack *b);
void                rr(t_stack *a, t_stack *b);
void                rrr(t_stack *a, t_stack *b);

int                 g_count;

# endif
