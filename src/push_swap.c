#include "push_swap.h"
#include <stdio.h>


int main(void)
{
    t_stack a;
    t_stack b;
    int ran;
    //void *data;

    stack_init(&a, 1, sizeof(int));
    stack_init(&b, 1, sizeof(int));

    for (int i = 0; i < 100; i++)
    {
        ran = (int)ft_random(100);
        stack_push(&a, &ran);
    }


    sort2(&a, &b);
    //sort(&a, &b);

    stack_print(&a);
    printf("\n\n\n%d", g_count);
    //while (!stack_is_empty(&a))
    //{
    //    data = stack_pop(&a); 
    //    printf("%d\n",*(int *)data);
    //    free(data);
    //}
    return (0);
}
