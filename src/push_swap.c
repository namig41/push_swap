/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 17:19:14 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/03/14 18:19:14 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	a.data = NULL;
	b.data = NULL;
	parse_arg(&a, &b, argc, argv);
	stack_sort(&a, &b);
	vector_destroy(&a);
	vector_destroy(&b);
	return (0);
}
