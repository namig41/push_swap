/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 17:19:20 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/03/14 18:11:32 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    valid_line(char *line, t_stack *a, t_stack *b)
{
    if (ft_strequ(line, PA))
		ph(a, b, NO_PR);
    else if (ft_strequ(line, PB)) 
		ph(b, a, NO_PR);
    else if (ft_strequ(line, SS))
		ss(a, b, NO_PR);
    else if (ft_strequ(line, SA))
		ss(a, NULL, NO_PR);
    else if (ft_strequ(line, SB))
		ss(b, NULL, NO_PR);
    else if (ft_strequ(line, RR))
		rr(a, b, NO_PR);
    else if (ft_strequ(line, RA))
		rr(a, NULL, NO_PR);
    else if (ft_strequ(line, RB))
		rr(b, NULL, NO_PR);
    else if (ft_strequ(line, RRR))
		rrr(a, b, NO_PR);
    else if (ft_strequ(line, RRA))
		rrr(a, NULL, NO_PR);
    else if (ft_strequ(line, RRB))
		rrr(b, NULL, NO_PR);
	else
		return (0);
	return (1);
}

void 	read_oper(t_stack *a, t_stack *b)
{
	char *line;
	t_vector vector;

    vector_init(&vector, a->capacity, a->element_size);
	vector_copy(&vector, a);
	vector_qsort(&vector);
	if (!vector_is_unique((&vector)))
		print_error();
	while (get_next_line(0, &line))
	{
		if (!valid_line(line, a, b))
			break ;
		ft_memdel((void **)&line);
	}
	if (vector_is_sorted(a) == 0)
		ft_putendl(OK);
	else
		ft_putendl(KO);
	vector_destroy(&vector);
}

int     main(int argc, char *argv[])
{
    t_stack a;
    t_stack b;

	parse_arg(&a, &b, argc, argv);
	if (!stack_is_empty(&a))
		read_oper(&a, &b);
	return (0);
}

