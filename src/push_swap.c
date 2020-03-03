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

    for (int i = 0; i < 100; i++)
    {
        ran = (int)ft_random(20);
        stack_push(&a, &ran);
    }
    
    //vector_init(&tmp, 1, sizeof(int));
    //for (int i = 0; i < 10; i++)
    //{
    //    ran = (int)ft_random(10);
    //    vector_push_back_data(&tmp, &ran);
    //}
    //stack_print(&tmp);
    //printf("%d\n", get_median(&tmp, tmp.size >> 1));

    sort2(&a, &b);
    stack_print(&a);
    printf("2 part: count = %d\n", g_count);
    //while (!stack_is_empty(&a))
    //{
    //    data = stack_pop(&a); 
    //    printf("%d\n",*(int *)data);
    //    free(data);
    //}
    return (0);
}
