/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 17:19:08 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/03/16 12:13:09 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

inline void	print_error(void)
{
	write(2, ERR_PR, sizeof(ERR_PR));
	exit(1);
}

static void	parse_str(t_stack *a, char *str, size_t len)
{
	size_t	k;
	size_t	j;
	int		tmp;

	j = 0;
	k = 0;
	while (!(tmp = !(j < len)))
	{
		while (ft_isescape(str[j]) && j < len)
			j++;
		while (!ft_isescape(str[j]) && j < len)
		{
			if (ft_isdigit(str[j + 1]) && str[j] == '-')
				;
			else if (!ft_isdigit(str[j]))
				print_error();
			tmp = ++j;
		}
		if (!tmp)
			break ;
		tmp = ft_atoi(str + k);
		stack_push(a, &tmp);
		k = j;
		j++;
	}
}

void		parse_arg(t_stack *a, t_stack *b, int argc, char *argv[])
{
	size_t	i;

	i = 1;
	stack_init(a, 1, sizeof(int));
	stack_init(b, 1, sizeof(int));
	while (i < argc)
	{
		parse_str(a, argv[i], ft_strlen(argv[i]));
		i++;
	}
}
