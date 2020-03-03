#include "push_swap.h"
#include <stdio.h>
#include <limits.h>


size_t 		get_min_index(t_vector *vector)
{
	size_t i;
	size_t min_i;
	int min;
	int tmp;

	i = 0;
	min = INT_MAX;
	while (i < vector->size)
	{	
		tmp = *(int *)vector_get_element(vector, i);
		if (min >= tmp)
		{
			min  = tmp;
			min_i = i;	
		}
		i++;
	}
	return (min_i);
}

int         vector_is_sorted(t_vector *vector)
{
    size_t i;
	size_t min_i;

    i = 0;
	min_i = get_min_index(vector);
    while (i < vector->size - 1)
    {
        if (*(int *)stack_get_element(vector, (min_i + i) % vector->size) < 
				*(int *)stack_get_element(vector, (min_i + i + 1) % vector->size))
            return (-1);
        i++;
    }
    return (min_i);
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
    else if (*(int *)stack_top(a) <= *(int *)stack_get_element(b, 0))
    {
        ph(b, a);
        while (*(int *)stack_top(b) == *(int *)stack_top(a))
        {
            ph(b, a);
            j++;
        }
        while (j >= 0)
        {
            if (mean <= *(int *)stack_top(a))
                rr(a, b);
            else
                rr(b, NULL);
            j--;
        }
    }
    else
    {
        tmp = stack_pop(a);
        median = get_median(b, b->size >> 1);
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
            //while (*(int *)stack_top(a) == *(int *)stack_top(b))
            while (*(int *)stack_top(a) == *(int *)tmp || *(int *)stack_top(a) == *(int *)stack_top(b))
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
            //while (*(int *)stack_top(a) == *(int *)stack_top(b))
            while (*(int *)stack_top(a) == *(int *)tmp || *(int *)stack_top(a) == *(int *)stack_top(b))
            {
                ph(b, a);
                l++;
            }
            stack_push(b, tmp);
            ft_memdel((void **)&tmp);
            while (l >= 0)
            {
                rr(b, NULL);
                l--;
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

int get_median(t_vector *vector, size_t med)
{
    size_t i;
    int pivot; 
    int tmp;
    t_vector lows;
    t_vector pivots;
    t_vector highs;

    i = 0;
    if (vector->size == 1)
        tmp = *(int *)vector_get_element(vector, 0);
    else
    {
        vector_init(&lows, 1, sizeof(int));
        vector_init(&highs, 1, sizeof(int));
        vector_init(&pivots, 1, sizeof(int));
        pivot = *(int *)vector_get_element(vector, ft_random(vector->size - 1));
        while (i < vector->size)
        {   
            tmp = *(int *)vector_get_element(vector, i);
            if (tmp < pivot)
                vector_push_back_data(&lows, &tmp);
            else if (tmp == pivot)
                vector_push_back_data(&pivots, &tmp);
            else
                vector_push_back_data(&highs, &tmp);
            i++;
        }
        if (med < lows.size)
           tmp = get_median(&lows, med);
        else if (med < lows.size + pivots.size)
            return (pivot);
        else
            tmp = get_median(&highs, med - lows.size - pivots.size);
        vector_destroy(&lows);
        vector_destroy(&highs);
        vector_destroy(&pivots);
    }
    return (tmp);
}

void sort2(t_stack *a, t_stack *b)
{
    int median;
    int max;
    int i;
    size_t j;
	size_t l;
    size_t count;

    i = 0;
    if (!stack_is_empty(a))
    {
        while (a->size > 2 && ((l = vector_is_sorted(a)) == -1))
        {
            i = 0;
            count = 0;
            median = get_median(a, a->size / 10); 
            while (i < a->size + count)
            {
                if (median < *(int *)stack_top(a))
                {
                    rr(a, NULL);
                    i++;
                }
                else
                {
                    if (stack_is_empty(b))
                        ph(b, a);
                    //else if (flag)
                    //{
                    //    sort_insert(a, b, median);
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
        }
        //stack_print(b);
		//stack_print(a);
        printf("l = %d\n\n", l);
        printf("count = %d\n\n", g_count);
        //printf("1 part: count = %d\n", g_count);

		stack_print(a);
		while (l-- >= 0)
			rr(a, NULL);	
		//stack_print(a);
        //if (!stack_is_empty(a) && !vector_is_sorted(a))
        //    ss(a, NULL); 
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
                           return ;
                    }
                    if (get_max_i(b, max) > b->size >> 1)
                        break ;
                }
            }
            else
            {
                rr(b, NULL);
                count++;
            }
        }

    }
    //stack_print(a);
}

