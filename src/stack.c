/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:16:56 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/02/26 19:12:59 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void        stack_init(t_stack *stack, size_t size, size_t element_size)
{
    vector_init(stack, size, element_size); 
}

void        stack_push(t_stack *stack, void *data)
{
    vector_push_back_data(stack, data);
}

void        stack_swap(t_stack *stack_a, t_stack *stack_b)
{
    if (vector_is_initialized(stack_a))
    {
        ft_memswap(vector_get_element(stack_a, stack_a->size - 1),
                    vector_get_element(stack_a, stack_a->size - 2),
                    stack_a->element_size);
    }
    if (vector_is_initialized(stack_b))
    {
        ft_memswap(vector_get_element(stack_b, stack_b->size - 1),
                vector_get_element(stack_b, stack_b->size - 2),
                stack_b->element_size);
    }
}

void        stack_rotate(t_stack *stack_a, t_stack *stack_b)
{
    void    *tmp;

    if (vector_is_initialized(stack_a))
    {
        tmp = vector_pop_back(stack_a);
        vector_push_front_data(stack_a, tmp);
    }
    if (vector_is_initialized(stack_b))
    {
        tmp = vector_pop_back(stack_b);
        vector_push_front_data(stack_b, tmp);
    }
}

void        stack_reverse(t_stack *stack_a, t_stack *stack_b)
{
    void    *tmp;

    if (vector_is_initialized(stack_a))
    {
        tmp = vector_pop_front(stack_a);
        vector_push_back_data(stack_a, tmp);
    }
    if (vector_is_initialized(stack_b))
    {
        tmp = vector_pop_front(stack_b);
        vector_push_back_data(stack_b, tmp);
    }
}

int         stack_is_sorted(t_stack *stack)
{
    void    *data;
    size_t  size;

    size = stack->size;
    while (--size > 0)
    {
        if (*(int *)vector_get_element(stack, size) < *(int *)vector_get_element(stack, size - 1))
            return (FALSE);
    }
    return (TRUE);
}
