#include "push_swap.h"

void        ss(t_stack *a, t_stack *b, char *oper)
{
    if (stack_is_initialized(a))
    {
        ft_memswap(stack_get_element(a, a->size - 1),
                    stack_get_element(a, a->size - 2),
                    a->element_size);
    }
    if (stack_is_initialized(b))
    {
        ft_memswap(stack_get_element(b, b->size - 1),
                    stack_get_element(b, b->size - 2),
                    b->element_size);
    }
	ft_putendl(oper);
    g_count++;
}

void        rr(t_stack *a, t_stack *b, char *oper)
{
    void    *tmp;

    if (stack_is_initialized(a))
    {
        tmp = stack_pop(a);
        vector_push_front_data(a, tmp);
    }
    if (stack_is_initialized(b))
    {
        tmp = stack_pop(b);
        vector_push_front_data(b, tmp);
    }
	ft_putendl(oper);
    g_count++;
}

void        rrr(t_stack *a, t_stack *b, char *oper)
{
    void    *tmp;

    if (stack_is_initialized(a))
    {
        tmp = vector_pop_front(a);
        stack_push(a, tmp);
    }
    if (stack_is_initialized(b))
    {
        tmp = vector_pop_front(b);
        stack_push(b, tmp);
    }
	ft_putendl(oper);
    g_count++;
}

void    ph(t_stack *a, t_stack *b, char *oper)
{
    void *data;

    if (!stack_is_empty(b))
    {
        data = stack_pop(b); 
        stack_push(a, data);
        ft_memdel(&data);
    }
	ft_putendl(oper);
    g_count++;
}

