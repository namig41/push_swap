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
	write(STDERR_FILENO, ERR_PR, sizeof(ERR_PR));
	exit(1);
}

static void	parse_str(t_stack *a, char *str, size_t len)
{
	int		num;
	size_t	j;
	t_ll	tmp;

	j = 0;
	while (!(tmp = !(j < len)))
	{
		num = j;
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
		if ((tmp = ft_atoll(str + num)) <= INT_MIN || tmp >= INT_MAX)
			print_error();
		num = tmp;
		j += vector_push_front_data(a, &num);
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
