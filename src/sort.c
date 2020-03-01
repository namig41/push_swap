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

static int get_mean(t_vector *vector, int num) 
{
   int mean;
   int tmp;
   size_t i;
   size_t s;

   i = 0;
   mean = 0;
   s = 0;
   while (i < vector->size)
   {
        tmp = *(int *)vector_get_element(vector, i); 
        if (tmp <= num)
        {
            mean += tmp;
            s++;
        }
        i++;
   }
   return (mean / s);
}

static int get_disp(t_vector *vector, int num)
{
    int disp;
    int mean;
    int tmp;
    size_t i;
    size_t j;
    size_t s;
    int flag;

    i = 0;
    mean = get_mean(vector, num);
    disp = 0;
    s = 0;
    while (i < vector->size)
    {
        flag = 1;
        tmp = *(int *)vector_get_element(vector, i);
        while (j < i)
        {
            if (*(int *)vector_get_element(vector, i) == tmp)
            {
                flag = 0;
                break;
            }
            j++;
        }
        if (flag && tmp <= num)
        {
            disp += (tmp - mean) * (tmp - mean);
            s++;
        }
        i++;
    }
    return (disp / s);
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

static void sort_insert(t_stack *a, t_stack *b, int mean)
{
    int j;
    int l;
    void *tmp;
    int median;


    j = 0;
    l = 0;
    if (*(int *)stack_top(a) >= *(int *)stack_top(b)) 
        ph(b, a);
    else
    {
        if (*(int *)stack_top(a) < *(int *)stack_get_element(b, 0))
        {
            ph(b, a);
            rr(b, NULL);
        }
        else
        {
            tmp = stack_pop(a);
            median = *(int *)stack_get_element(a, a->size >> 1);
            if (*(int *)tmp >= median)
            {
                while (*(int *)tmp < *(int *)stack_top(b))
                {
                    if (mean <= *(int *)stack_top(a))
                        rr(a, b);
                    else
                        rr(b, NULL);
                    l++;
                }
                while (*(int *)stack_top(b) == *(int *)stack_top(a))
                    ph(b, a);
                stack_push(b, tmp);
                ft_memdel((void **)&tmp);
                while (l > 0)
                {
                    rrr(b, NULL);
                    l--;
                }
            }
            else
            {
                while (*(int *)tmp > *(int *)stack_get_element(b, 0))
                {
                    rrr(b, NULL);
                    l++;
                }
                l++;
                stack_push(b, tmp);
                while (*(int *)stack_top(b) == *(int *)stack_top(a))
                    ph(b, a);
                ft_memdel((void **)&tmp);
                while (l > 0)
                {
                    rr(b, NULL);
                    l--;
                }
            }
        }
    }
}

static size_t get_max_i(t_vector *vec, int max)
{
    size_t i;

    i = 0;
    while (i < vec->size)
    {
        if (*(int *)vector_get_element(vec, vec->size - i - 1) == max)
            return (vec->size - i - 1);
        i++;
    }
    return (0);
}

void sort2(t_stack *a, t_stack *b)
{
    int mean;
    int max;
    size_t i;
    size_t j;
    size_t count;
    int flag;

    flag = 1;
    printf("mean = %d\n", get_mean(a, INT_MAX));
    printf("disp = %d\n", get_disp(a, INT_MAX));
    if (!stack_is_empty(a))
    {
        while (a->size > 2)
        {
            i = 0;
            count = 0;
            mean = get_mean(a, INT_MAX); 
            //if (stack_is_empty(b))
                //mean >>= 2;

            //printf("disp = %d\n", get_disp(a, mean));
            //printf("disp = %d\n", get_mean(a, mean));
            //printf("mean = %d\n", mean);
            while (i < a->size + count)
            {
                if (mean < *(int *)stack_top(a))
                    rr(a, NULL);
                else
                {
                    if (stack_is_empty(b))
                        ph(b, a);
                    //else if (flag)
                    //{
                    //    sort_insert(a, b, mean);
                    //}
                    else if (*(int *)stack_top(b) > *(int *)stack_top(a))
                    {
                        ph(b, a);
                        ss(b, NULL);
                    }
                    else
                        ph(b, a);
                    count++;
                }
                i++;
            }
            flag = 0;
            //stack_print(b);
        }
        //stack_print(b);
        //printf("count = %d\n\n", g_count);
        printf("count = %d\n", g_count);
        if (!stack_is_empty(a) && !stack_is_sorted(a))
            ss(a, NULL); 
        count = 0;
        while (!stack_is_empty(b))
        {
            max = get_max(b, b->size); 
            if (*(int *)stack_top(b) == max)
            {
                ph(a, b);
                max = get_max(b, b->size); 
                if (get_max_i(b, max) > b->size >> 1)
                    continue ;
                j = 0;
                while (count > 0 && count--)
                {
                    rrr(b, NULL);
                    if (b->size >= 2 && *(int *)stack_get_element(b, b->size - 2) == max)
                    {
                        ss(b, NULL);
                        ph(a, b);
                        max = get_max(b, b->size); 
                    }
                    while (*(int *)stack_top(b) == max)
                    {
                        ph(a, b);
                        if (stack_is_empty(b))
                            break ;
                    }
                    if (get_max_i(b, max) > b->size >> 1)
                        break ;
                }
                //count = 0;
            }
            else
            {
                rr(b, NULL);
                count++;
            }
        }
    }
    //stack_print(a);
    printf("finished count = %d\n", g_count);
}

