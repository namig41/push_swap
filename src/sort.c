#include "push_swap.h"
#include <stdio.h>
#include <limits.h>

size_t 		get_max_index(t_vector *vector)
{
	size_t i;
	size_t max_i;
	int tmp;

    int max;
	i = 0;
	max = INT_MIN;
	while (i < vector->size)
	{	
		tmp = *(int *)vector_get_element(vector, i);
		if (max <= tmp)
		{
			max = tmp;
			max_i = i;	
		}
        i++;
	}
	return (max_i);
}

size_t 		get_min_index(t_vector *vector)
{
	size_t i;
	size_t min_i;
	int min;
	int tmp;

	i = 0;
	min = INT_MAX;
	while (i < vector->size)
		tmp = *(int *)vector_get_element(vector, i);
    {	
		if (min >= tmp)
		{
			min = tmp;
			min_i = i;	
		}
		i++;
	}
	return (min_i);
}

int         vector_is_sorted(t_vector *vector)
{
    size_t i;
	size_t max_i;

    if (vector->size < 2)
        return (-1);
    i = 0;
	max_i = get_max_index(vector);
    while (i < vector->size - 1)
    {
        if (*(int *)vector_get_element(vector, (max_i + i) % vector->size) <
				*(int *)vector_get_element(vector, (max_i + i + 1) % vector->size))
            return (-1);
        i++;
    }
    return (max_i);
}

int     vector_is_unique(t_vector *vector)
{
    size_t i;

    i = 0;
    while (i < vector->size - 1)
    {
        if (*(int *)vector_get_element(vector, i) == *(int *)vector_get_element(vector, i + 1))
            return (0);
        i++;
    }
    return (1);
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


static int get_max(t_stack *stack, size_t size)
{
   int max; 
   size_t i;

   i = 0;
   max = INT_MIN;
   while (i < size)
   {
        max = ft_max_l(max, *(int *)stack_get_element(stack, stack->size - i - 1));
        i++;
   }
   return (max);
}

static int get_min(t_stack *stack, size_t size)
{
   int min; 
   size_t i;

   i = 0;
   min = INT_MAX;
   while (i < size)
   {
        min = ft_min(min, *(int *)stack_get_element(stack, stack->size - i - 1));
        i++;
   }
   return (min);
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

int get_index(t_stack *a, int elem) 
{
    size_t i;
    size_t j;
    
    i = 0;
    j = get_max_index(a);
    while (i < a->size)
    {
        if (*(int *)stack_get_element(a, (i + j) % a->size) < elem)
            break ;
        i++;
    }
    return (a->size - i);
}

static int get_opt_index(t_stack *stack, int elem)
{
	size_t i;

	i = 0;
	while (i <= stack->size >> 1)
	{
		if (*(int *)stack_get_element(stack, stack->size - i - 1) == elem)
			return (i);
		i++;
	}
	i = 0;
	while (i < stack->size >> 1)
	{
		if (*(int *)stack_get_element(stack, i) == elem)
			return (-i - 1);
		i++;
	}
	return ((stack->size >> 1) + 1);
}

int get_true_position(t_vector *vector, int elem)
{
	size_t i;

	i = 0;
	while (i < vector->size)
	{
		if (*(int *)vector_get_element(vector, i) == elem)
			break ;
		i++;
	}
	return (vector->size - i);
}

int get_opt_elem(t_stack *a, t_stack *b, int count, t_vector *vector)
{
    size_t i;
    size_t j;
    int elem;
    int opt_elem;
    int tmp_elem;
    int total_cost;
    int cost_a;
    int cost_b;
    int opt_cost;

    i = 0;
    opt_cost = INT_MAX;
    while (i < b->size)
    {
        j = 0;
        cost_a = 0;
        elem = *(int *)stack_get_element(b, b->size - i - 1);
		cost_b = get_opt_index(b, elem);
        cost_a = get_index(a, elem) - count;
        if (cost_a * cost_b > 0) 
            total_cost = ft_abs(ft_abs(cost_a) - ft_abs(cost_b));
        else
            total_cost = ft_abs(cost_a) + ft_abs(cost_b);
		total_cost += get_true_position(vector, elem);
        //total_cost = ft_abs(cost_a) + ft_abs(cost_b);
        //printf("total_cost = %d\n", total_cost);
        if (opt_cost > total_cost)
        {
            opt_cost = total_cost;
            opt_elem = elem;
        }
        i++;
    }
    return (opt_elem);
}


void 	stack_sort_part_1(t_stack *a, t_stack *b, t_vector *vector)
{
	int l;
    int median;
    int median_b;
    size_t i;
    size_t count;

	while (a->size > 3)
	{
		i = 0;
		count = 0; 
		median = get_median(a, a->size >> 1); 
		while (a->size > 3 && i < a->size + count)
		{
			if (median < *(int *)stack_top(a))
			{
				rr(a, NULL, RA);
				i++;
			}
			else
			{
                median_b = b->size ? get_median(b, b->size >> 1) : INT_MIN; 
                if (median_b > *(int *)stack_top(a))
                {
                    ph(b, a, PB);
                    if (median < *(int *)stack_top(a))
                        rr(a, b, RR);
                    else
                        rr(b, NULL, RB);
                }
                else
                    ph(b, a, PB);
                count++;
                if ((l = vector_is_sorted(a)) != -1)
                    return ;
			}
			i++;
		}
	}
	if (l == -1)
		ss(a, NULL, SA);
}

void stack_sort_part_2(t_stack *a, t_stack *b, t_vector *vector)
{ 
	int a_i;
	int b_i;
	int count;
	int opt_elem;
	
	count = vector_is_sorted(a);
    if (count == -1)
        stack_print(a);
    while (!stack_is_empty(b))
    {
        opt_elem = get_opt_elem(a, b, count, vector);
        a_i = get_index(a, opt_elem);
		b_i = get_opt_index(b, opt_elem);
		a_i -= count;
		//printf("opt_elem = %d\na_i = %d\nb_i = %d\n", opt_elem, a_i, b_i);

		if (a_i >= 0 && b_i >= 0)
		{
			while (a_i > 0 && b_i > 0)
			{
				rr(a, b, RR);
				count++;
				a_i--;
				b_i--;
			}
			while (b_i-- > 0)
            {
                rr(b, NULL, RB);
            }
            while (a_i-- > 0)
			{
				rr(a, NULL, RA);
				count++;
			}
		}
        else if (a_i <= 0 && b_i <= 0)
        {
			a_i = -a_i;
			b_i = -b_i;
			while (b_i > 0 && a_i > 0)
			{
				rrr(a, b, RRR);
				count--;
				a_i--;
				b_i--;
			}
			while (b_i-- > 0)
				rrr(b, NULL, RRB);
            while (a_i-- > 0)
			{
				rrr(a, NULL, RRA);
				count--;
			}
        }
		else
		{
			if (a_i >= 0 && b_i <= 0)
			{
				b_i = -b_i;
				while (b_i-- > 0)
					rrr(b, NULL, RRB);
				while (a_i-- > 0)
				{
					rr(a, NULL, RA);
					count++;
				}
			}
            else if (a_i <= 0 && b_i >= 0)
			{
				a_i = -a_i;
				while (b_i-- > 0)
                {
                    if (*(int *)stack_second(b) == opt_elem)
                    {
                       ss(b, NULL, SB);
                       break ;
                    }
                    rr(b, NULL, RB);
                }
				while (a_i-- > 0)
				{
					rrr(a, NULL, RRA);
					count--;
				}
			}
		}
		//printf("STACK B\n");
		//stack_print(b);
        ph(a, b, PA);
		//printf("STACK A\n");
		//stack_print(a);
        //printf("g_count = %d\n", g_count);
    }
	a_i = vector_is_sorted(a);
    if (a_i == -1)
        stack_print(a);
    if (a_i == 0)
        return ;
	if ((a->size >> 1) > a_i)
	{
		while (a_i-- > 0)
		{
			rrr(a, NULL, RRA);
		}
	}
	else
	{
		a_i = a->size - a_i;
		while (a_i-- > 0)
		{
			rr(a, NULL, RA);
		}
	}
}


void stack_sort(t_stack *a, t_stack *b)
{
	t_vector vec;

	if (stack_is_empty(a))
		return ;
    vector_init(&vec, a->capacity, a->element_size);
    vector_copy(&vec, a);
    vector_qsort(&vec);
    if (vector_is_unique(&vec))
    {
        stack_sort_part_1(a, b, &vec);
        //printf("part 1: g_count = %d\n", g_count);
        stack_sort_part_2(a, b, &vec);
        //printf("part 2: g_count = %d\n\n", g_count);
    }
	vector_destroy(&vec);
}

