#include "push_swap.h"
#include <stdio.h>

int         stack_is_sorted(t_stack *stack)
{
    size_t  size;

    size = stack->size;
    while (--size > 0)
    {
        if (*(int *)stack_get_element(stack, size) < *(int *)stack_get_element(stack, size - 1))
            return (FALSE);
    }
    return (TRUE);
}

void stack_print(t_stack *stack)
{
    int i;

    if (!stack_is_empty(stack))
    {
        i = (int)stack->size - 1;
        while (i >= 0)
        {
            printf("%d\n", *(int *)stack_get_element(stack, i));
            i--;
        }
        printf("\n");
    }
}

static int get_max(t_stack *stack)
{
    int max;
    size_t i;

    i = 0;
    max = 0;
    while (i < stack->size)
    {
        max = ft_max_l(max, *(int *)stack_get_element(stack, i));
        i++;
    }
    return (max);
}

static int get_min(t_stack *stack)
{
    int min;
    size_t i;

    i = 0;
    min = 10000;
    while (i < stack->size)
    {
        min = ft_min_l(min, *(int *)stack_get_element(stack, i));
        i++;
    }
    return (min);
}


void    stack_quick_sort(t_stack *a, t_stack *b)
{
    int max;
    int i;

    max = 0;
    if (!stack_is_empty(a))
    {
        stack_print(a);
        max = *(int *)stack_top(a);
        ph(b, a);
        while (!stack_is_empty(a))
        {
            i = 0;
            stack_print(b);
            if (*(int *)stack_top(a) > max)  
            {
                max = *(int *)stack_top(a);
                ph(b, a);
                rr(b, NULL);
                continue ;
            }
            if (*(int *)stack_top(a) == *(int *)stack_top(b))
            {
                ph(b, a);
                continue ;
            }
            while (*(int *)stack_top(a) > *(int *)stack_top(b))
            {
                rr(b, NULL);
                i++;
            }
            ph(b, a);
            while (i > 0)
            {
                rrr(b, NULL);
                i--;
            }
        }
    }
}

