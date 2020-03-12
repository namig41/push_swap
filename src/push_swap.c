#include "push_swap.h"
# include <stdio.h>
# define MAX_RANGE 500

int main(void)
{
    t_stack a;
    t_stack b;
    t_vector vector;
    int ran;
    //void *data;
    //t_vector tmp;

    stack_init(&a, 1, sizeof(int));
    stack_init(&b, 1, sizeof(int));
    vector_init(&vector, 1, sizeof(int));

    for (int i=0; i < MAX_RANGE; i++)
        vector_push_back_data(&a, &i);

    for (int j=0; j < 500; j++)
    {
        for (int i=0; i < MAX_RANGE; i++)
            ft_memswap(vector_get_element(&a, i), vector_get_element(&a, (int)ft_random(a.size - 1)), a.element_size);
        stack_sort(&a, &b);
        //return (0);
        g_count = 0;
    }
    return (0);
}
