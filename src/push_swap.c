#include "push_swap.h"
# include <stdio.h>

int main(void)
{
    t_stack a;
    t_stack b;
    int ran;
    //void *data;
    //t_vector tmp;

    stack_init(&a, 1, sizeof(int));
    stack_init(&b, 1, sizeof(int));
    for (int j = 1; j < 100; j++)
    {
		printf("max = %d\n", j*10);
        for (int i = 0; i < 500; i++)
        {
            ran = (int)ft_random(j*10);
            stack_push(&a, &ran);
        }
        stack_sort(&a, &b);
		//stack_print(&a);
        vector_clear(&a);
        printf("count = %d\n", g_count);
        g_count = 0;
    }
    return (0);
}
