/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 17:18:54 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/03/14 18:04:21 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void        ss(t_stack *a, t_stack *b, char *oper)
{
    if (stack_is_initialized(a) && a->size > 2)
        ft_memswap(stack_top(a), stack_second(a), a->element_size);
    if (stack_is_initialized(b) && b->size > 2)
        ft_memswap(stack_top(b), stack_second(b), b->element_size);
	if (oper)
		ft_putendl(oper);
    g_count++;
}

void        rr(t_stack *a, t_stack *b, char *oper)
{
    void    *tmp;

    if (!stack_is_empty(a))
    {
        tmp = stack_pop(a);
        vector_push_front_data(a, tmp);
    }
    if (!stack_is_empty(b))
    {
        tmp = stack_pop(b);
        vector_push_front_data(b, tmp);
    }
	if (oper)
		ft_putendl(oper);
    g_count++;
}

void        rrr(t_stack *a, t_stack *b, char *oper)
{
    void    *tmp;

    if (!stack_is_empty(a))
    {
        tmp = vector_pop_front(a);
        stack_push(a, tmp);
    }
    if (!stack_is_empty(b))
    {
        tmp = vector_pop_front(b);
        stack_push(b, tmp);
    }
	if (oper)
		ft_putendl(oper);
    g_count++;
}

void    ph(t_stack *a, t_stack *b, char *oper)
{
    void *data;

    if (!stack_is_empty(b))
    {
        data = stack_pop(b); 
        stack_push(a, data);
        ft_memdel(&data);
    }
	if (oper)
		ft_putendl(oper);
    g_count++;
}

