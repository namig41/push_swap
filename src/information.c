/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   information.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 17:37:57 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/08/04 17:37:58 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_index(t_stack *a, int elem)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = vector_get_maxi(a);
	while (i < a->size)
	{
		if (*(int *)stack_get_element(a, (i + j) % a->size) < elem)
			break ;
		i++;
	}
	return (a->size - i);
}

int			get_opt_index(t_stack *stack, int elem)
{
	size_t	i;

	i = 0;
	while (i <= stack->size >> 1)
	{
		if (*(int *)stack_get_element(stack, stack->size - i - 1) == elem)
			return (i);
		i++;
	}
	i = 0;
	while (i < stack->size >> 1)
	{
		if (*(int *)stack_get_element(stack, i) == elem)
			return (-i - 1);
		i++;
	}
	return ((stack->size >> 1) + 1);
}

int			get_true_position(t_vector *vector, int elem)
{
	size_t	i;

	i = 0;
	while (i < vector->size)
	{
		if (*(int *)vector_get_element(vector, i) == elem)
			break ;
		i++;
	}
	return (vector->size - i);
}

int			get_opt_elem(t_stack *a, t_stack *b, int count, t_vector *vector)
{
	int		elem;
	int		opt_elem;
	int		cost[4];
	size_t	i;

	i = 0;
	cost[OPT] = INT_MAX;
	while (i < b->size)
	{
		elem = *(int *)stack_get_element(b, b->size - i - 1);
		cost[A] = get_index(a, elem) - count;
		cost[B] = get_opt_index(b, elem);
		if (cost[A] * cost[B] > 0)
			cost[TOTAL] = ft_abs(ft_abs(cost[A]) - ft_abs(cost[B]));
		else
			cost[TOTAL] = ft_abs(cost[A]) + ft_abs(cost[B]);
		cost[TOTAL] += get_true_position(vector, elem);
		if (cost[OPT] > cost[TOTAL])
		{
			cost[OPT] = cost[TOTAL];
			opt_elem = elem;
		}
		i++;
	}
	return (opt_elem);
}
