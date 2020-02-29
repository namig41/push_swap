#include "push_swap.h"
#include <stdio.h>

int         stack_is_sorted(t_stack *stack)
{
    size_t i;

    i = 0;
    while (i < stack->size - 1)
    {
        if (*(int *)stack_get_element(stack, i) < *(int *)stack_get_element(stack, i + 1))
            return (FALSE);
        i++;
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

void    sort(t_stack *a, t_stack *b)
{
    int max;
    int i;

    max = 0;
    if (!stack_is_empty(a))
    {
        max = *(int *)stack_top(a);
        ph(b, a);
        while (!stack_is_empty(a))
        {
            i = 0;
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

static int get_median(t_stack *stack)
{
   int max; 
   int min;
   size_t i;

   max = 0;
   min = 100000;
   i = 0;
   while (i < stack->size)
   {
        max = ft_max(max, *(int *)stack_get_element(stack, stack->size - i - 1));
        min = ft_min(min, *(int *)stack_get_element(stack, stack->size - i - 1));
        i++;
   }
   return ((max + min) >> 1);
}


static int get_max(t_stack *stack, size_t size)
{
   int max; 
   size_t i;

   max = 0;
   i = 0;
   while (i < size)
   {
        max = ft_max(max, *(int *)stack_get_element(stack, stack->size - i - 1));
        i++;
   }
   return (max);
}

void sort2(t_stack *a, t_stack *b)
{
    t_stack tmp;
    int med;
    int max;
    size_t i;
    size_t j;
    size_t count;
    size_t *size;

    stack_init(&tmp, 1, sizeof(size_t));
    if (!stack_is_empty(a))
    {
        while (a->size > 2)
        {
            i = 0;
            count = 0;
            med = get_median(a); 
            while (i < a->size + count)
            {
                if (med <= *(int *)stack_top(a))
                    rr(a, NULL);
                else
                {
                    ph(b, a);
                    count++;
                }
                i++;
            }
            stack_push(&tmp, &count);
        }
        if (!stack_is_sorted(a))
            ss(a, NULL); 
        while (!stack_is_empty(&tmp))
        {
            i = 0;
            count = 0;
            size = (size_t *)stack_pop(&tmp);
            max = get_max(b, *size); 
            while (i < *size)
            {
                if (*(int *)stack_top(b) == max)
                {
                    ph(a, b);
                    i++;
                    j = 0;
                    while (j < count)
                    {
                        rrr(b, NULL);
                        j++;
                    }
                    max = get_max(b, *size - i); 
                    count = 0;
                }
                else
                {
                    rr(b, NULL);
                    count++;
                }
            }
            ft_memdel((void **)&size);
        }
    }
}

