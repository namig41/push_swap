#include "push_swap.h"
#include <stdio.h>
#include <limits.h>

size_t 		get_max_index(t_vector *vector)
{
	size_t i;
	size_t max_i;
	int max;
	int tmp;

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
	{	
		tmp = *(int *)vector_get_element(vector, i);
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
	return (i);
}

int get_opt_elem(t_stack *a, t_stack *b, t_vector *vector)
{
    size_t i;
    size_t j;
    int elem;
    int opt_elem;
    int tmp_elem;
    int cost;
    int opt_cost;

    i = 0;
    opt_cost = INT_MAX;
    while (i < b->size)
    {
        j = 0;
        elem = *(int *)stack_get_element(b, b->size - i - 1);
		cost = (i > (b->size >> 1)) ? b->size - i - 1 : i;
		cost += (a->size - get_true_position(vector, elem));
        if (opt_cost > cost)
        {
            opt_cost = cost;
            opt_elem = elem;
        }
        i++;
    }
    return (opt_elem);
}


void 	stack_sort_part_1(t_stack *a, t_stack *b)
{
	int l;
    int median;
    size_t i;
    size_t count;

	while (a->size > 2)
	{
		i = 0;
		count = 0; 
		median = get_median(a, a->size >> 1); 
		while (a->size > 2 && i < a->size + count)
		{
			if (((l = vector_is_sorted(a)) != -1))
				return ;
			if (median < *(int *)stack_top(a))
			{
				rr(a, NULL);
				i++;
			}
			else
			{
				ph(b, a);
				count++;
			}
			i++;
		}
	}
	if (l == -1)
		ss(a, NULL);
}

void stack_sort_part_2(t_stack *a, t_stack *b, t_vector *vector)
{ 
	int a_i;
	int b_i;
	int count;
	int opt_elem;
	
	count = vector_is_sorted(a);
    while (!stack_is_empty(b))
    {
        opt_elem = get_opt_elem(a, b, vector);
        a_i = get_index(a, opt_elem);
		b_i = get_opt_index(b, opt_elem);
		a_i -= count;
		//printf("opt_elem = %d\na_i = %d\nb_i = %d\n", opt_elem, a_i, b_i);

        //while (*(int *)stack_top(b) != opt_elem)
		//{
		//	rr(b, NULL);
		//}
		if (a_i >= 0 && b_i >= 0)
		{
			while (a_i > 0 && b_i > 0)
			{
				rr(a, b);
				count++;
				a_i--;
				b_i--;
			}
			while (b_i-- > 0)
				rr(b, NULL);
            while (a_i-- > 0)
			{
				rr(a, NULL);
				count++;
			}
		}
        else if (a_i <= 0 && b_i <= 0)
        {
			a_i = -a_i;
			b_i = -b_i;
			while (b_i > 0 && a_i > 0)
			{
				rrr(a, b);
				count--;
				a_i--;
				b_i--;
			}
			while (b_i-- > 0)
				rrr(b, NULL);
            while (a_i-- > 0)
			{
				rrr(a, NULL);
				count--;
			}
        }
		else
		{
			if (a_i >= 0 && b_i <= 0)
			{
				b_i = -b_i;
				while (b_i-- > 0)
					rrr(b, NULL);
				while (a_i-- > 0)
				{
					rr(a, NULL);
					count++;
				}
			}
			if (a_i <= 0 && b_i >= 0)
			{
				a_i = -a_i;
				while (b_i-- > 0)
					rr(b, NULL);
				while (a_i-- > 0)
				{
					rrr(a, NULL);
					count--;
				}
			}
		}
        ph(a, b);
		//printf("STACK A\n");
		//stack_print(a);
		//printf("STACK B\n");
		//stack_print(b);
    }
	a_i = vector_is_sorted(a);
	if ((a->size >> 1) > a_i)
	{
		a_i = a->size - a_i;
		while (a_i-- > 0)
		{
			rr(a, NULL);
		}
	}
	else
	{
		while (a_i-- > 0)
		{
			rrr(a, NULL);
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
	stack_sort_part_1(a, b);
	stack_sort_part_2(a, b, &vec);
	vector_destroy(&vec);
}

