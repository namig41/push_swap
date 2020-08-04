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

int g_count;
int g_opt_element;

static void		stack_sort_part21a(t_stack *a, t_stack *b, int *a_i, int *b_i)
{
	while ((*a_i) > 0 && (*b_i) > 0)
	{
		rr(a, b, RR);
		g_count++;
		(*a_i)--;
		(*b_i)--;
	}
	while ((*b_i)-- > 0)
		rr(b, NULL, RB);
	while ((*a_i)-- > 0)
	{
		rr(a, NULL, RA);
		g_count++;
	}
}

static void		stack_sort_part21b(t_stack *a, t_stack *b, int *a_i, int *b_i)
{
	*a_i = -*a_i;
	*b_i = -*b_i;
	while (*b_i > 0 && *a_i > 0)
	{
		rrr(a, b, RRR);
		g_count--;
		(*a_i)--;
		(*b_i)--;
	}
	while ((*b_i)-- > 0)
		rrr(b, NULL, RRB);
	while ((*a_i)-- > 0)
	{
		rrr(a, NULL, RRA);
		g_count--;
	}
}

static void		stack_sort_part21c(t_stack *a, t_stack *b, int *a_i, int *b_i)
{
	if (*a_i >= 0 && *b_i <= 0)
	{
		*b_i = -*b_i;
		while ((*b_i)-- > 0)
			rrr(b, NULL, RRB);
		while ((*a_i)-- > 0)
		{
			rr(a, NULL, RA);
			g_count++;
		}
	}
	else if (*a_i <= 0 && *b_i >= 0)
	{
		*a_i = -*a_i;
		while ((*b_i)-- > 0)
			rr(b, NULL, RB);
		while ((*a_i)-- > 0)
		{
			rrr(a, NULL, RRA);
			g_count--;
		}
	}
}

static void		stack_sort_part22(t_stack *a)
{
	int			tmp;

	tmp = vector_is_sorted(a);
	if (!tmp)
		return ;
	if ((a->size >> 1) > tmp)
		while (tmp-- > 0)
			rrr(a, NULL, RRA);
	else
	{
		tmp = a->size - tmp;
		while (tmp-- > 0)
			rr(a, NULL, RA);
	}
}

void			stack_sort_part_2(t_stack *a, t_stack *b, t_vector *vector)
{
	int			a_i;
	int			b_i;

	g_count = vector_is_sorted(a);
	while (!stack_is_empty(b))
	{
		g_opt_element = get_opt_elem(a, b, g_count, vector);
		a_i = get_index(a, g_opt_element);
		b_i = get_opt_index(b, g_opt_element);
		a_i -= g_count;
		if (a_i >= 0 && b_i >= 0)
			stack_sort_part21a(a, b, &a_i, &b_i);
		else if (a_i <= 0 && b_i <= 0)
			stack_sort_part21b(a, b, &a_i, &b_i);
		else
			stack_sort_part21c(a, b, &a_i, &b_i);
		ph(a, b, PA);
	}
	stack_sort_part22(a);
}
