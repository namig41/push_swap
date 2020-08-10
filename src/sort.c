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

void			stack_sort(t_stack *a, t_stack *b)
{
	t_vector	vec;

	vec.data = NULL;
	if (stack_is_empty(a) || a->size == 1)
		return ;
	vector_init(&vec, a->capacity, a->element_size);
	vector_copy(&vec, a);
	vector_qsort(&vec);
	if (vector_is_unique(&vec))
	{
		stack_sort_part_1(a, b, &vec);
		stack_sort_part_2(a, b, &vec);
	}
	vector_destroy(&vec);
}
