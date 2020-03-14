/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 17:19:08 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/03/14 20:08:18 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

inline void print_error(void)
{
	write(2, ERR_PR, sizeof(ERR_PR));
	exit(1);
}

void 	parse_arg(t_stack *a, t_stack *b, int argc, char *argv[])
{
	int num;
    size_t i;
	size_t j;
	size_t k;
	size_t len;
	int flag;

	i = 1;
    stack_init(a, 1, sizeof(int));
    stack_init(b, 1, sizeof(int));
    while (i < argc)
    {
		j = 0;
		k = 0;
		len = ft_strlen(argv[i]);
		while (j < len)
		{
			flag = 0;
			while (ft_isescape(argv[i][j]) && j < len)
				j++;
			while (!ft_isescape(argv[i][j]) && j < len)
			{
				if (ft_isdigit(argv[i][j + 1]) && argv[i][j] == '-')
					;
				else if (!ft_isdigit(argv[i][j]))
					print_error();
				flag = 1;
				j++;
			}
			if (!flag)
				break ;
			num = ft_atoi(argv[i] + k);
			stack_push(a, &num);
			k = j;
			j++;
		}
        i++;
    }
}

