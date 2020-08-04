/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 20:08:34 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/03/16 12:18:47 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		stack_sort_part_1a(t_stack *a, t_stack *b, int med, size_t *c)
{
	int			median_b;

	median_b = b->size ? vector_get_median(b, b->size >> 1) : INT_MIN;
	if (median_b > *(int *)stack_top(a))
	{
		ph(b, a, PB);
		if (med < *(int *)stack_top(a))
			rr(a, b, RR);
		else
			rr(b, NULL, RB);
	}
	else
		ph(b, a, PB);
	(*c)++;
	return (vector_is_sorted(a));
}

void			stack_sort_part_1(t_stack *a, t_stack *b, t_vector *vector)
{
	int			l;
	int			median;
	size_t		i;
	size_t		count;

	while ((l = vector_is_sorted(a)) == -1 && a->size > 3)
	{
		i = 0;
		count = 0;
		median = vector_get_median(a, a->size >> 1);
		while (a->size > 3 && i < a->size + count)
		{
			if (median < *(int *)stack_top(a))
			{
				rr(a, NULL, RA);
				i++;
			}
			else if (stack_sort_part_1a(a, b, median, &count) != -1)
				return ;
			i++;
		}
	}
	if (l == -1)
		ss(a, NULL, SA);
}
