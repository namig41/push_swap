/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 17:19:20 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/03/16 12:02:16 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			valid_line(t_stack *a, t_stack *b, char *line)
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
		print_error(a, b);
}

static void		read_oper(t_stack *a, t_stack *b)
{
	char		*line;
	t_vector	vector;

	vector.data = NULL;
	vector_init(&vector, a->capacity, a->element_size);
	vector_copy(&vector, a);
	vector_qsort(&vector);
	if (!vector_is_unique(&vector))
		print_error(a, b);
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (!*line)
			break ;
		valid_line(a, b, line);
		ft_memdel((void **)&line);
	}
	if (!vector_is_sorted(a) && vector_is_empty(b))
		ft_putendl(OK);
	else
		ft_putendl(KO);
	ft_memdel((void **)&line);
	vector_destroy(&vector);
}

int				main(int argc, char *argv[])
{
	t_stack		a;
	t_stack		b;

	a.data = NULL;
	b.data = NULL;
	parse_arg(&a, &b, argc, argv);
	if (!stack_is_empty(&a))
		read_oper(&a, &b);
	vector_destroy(&a);
	vector_destroy(&b);
	return (0);
}
