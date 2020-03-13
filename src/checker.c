#include "push_swap.h"

static void print_error(void)
{
	write(2, ERR, sizeof(ERR));
	exit(1);
}

void    valid_line(char *line, t_stack *a, t_stack *b)
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
		print_error();
}

void 	read_oper(t_stack *a, t_stack *b)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		valid_line(line, a, b);
		ft_memdel((void **)&line);
	}
	if (vector_is_sorted(a) == 0)
		ft_putendl("OK");
	else
		ft_putendl("KO");
}

int     main(int argc, char *argv[])
{
	int num;
    size_t i;
	size_t j;
	size_t len;
    t_stack a;
    t_stack b;

	i = 1;
    stack_init(&a, 1, sizeof(int));
    stack_init(&b, 1, sizeof(int));
    while (i < argc)
    {
		j = 0;
		len = ft_strlen(argv[i]);
		while (j < len)
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				print_error();
			j++;
		}
		num = ft_atoi(argv[i]);
        stack_push(&a, &num);
        i++;
    }
	if (!stack_is_empty(&a))
		read_oper(&a, &b);
	return (0);
}

