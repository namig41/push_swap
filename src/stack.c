#include "push_swap.h"
#include <stdio.h>

void        stack_swap(t_stack *a, t_stack *b)
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
}

void        stack_rotate(t_stack *a, t_stack *b)
{
    void    *tmp;

    if (stack_is_initialized(b))
    {
        tmp = stack_pop(a);
        vector_push_front_data(a, tmp);
    }
    if (stack_is_initialized(b))
    {
        tmp = stack_pop(b);
        vector_push_front_data(b, tmp);
    }
}

void        stack_reverse(t_stack *a, t_stack *b)
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
}

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

static void stack_print(t_stack *a, t_stack *b)
{
    if (!stack_is_empty(a) && !stack_is_empty(b))
    {
        for (int i = (int)a->size - 1; i >= 0; i--)
        {
            printf("%d\n", *(int *)stack_get_element(a, i));
        }
    }
}

void    stack_quick_sort(t_stack *a, t_stack *b)
{
    int median;    
    
    median = *(int *)stack_get_element(a, a->size >> 1);
    while (!stack_is_sorted(a))
    {
       if (median < *(int *)stack_top(a))
           stack_rotate(a, NULL);
       else if (median > *(int *)stack_top(a))
           stack_move_data(b, stack_pop(a));
       else 
            median = *(int *)stack_get_element(a, a->size >> 1);
        stack_print(a, b);
    }
    while (!stack_is_empty(b))
        stack_move_data(a, stack_pop(b));
}
