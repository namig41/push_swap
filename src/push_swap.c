/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:05:46 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/02/27 19:25:22 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


int main(void)
{
    t_stack a;
    t_stack b;
    int ran;
    void *data;

    stack_init(&a, 1, sizeof(int));
    stack_init(&b, 1, sizeof(int)); 

    for (int i=0; i < 16; i++)
    {  
        ran = (int)ft_random(10);
        stack_push(&a, &ran);
    }

    //printf("%d\n", *(int *)stack_top(&a));

    stack_quick_sort(&a, &b);

    while (!stack_is_empty(&a))
    {
        data = stack_pop(&a); 
        printf("%d\n", *(int *)data);
        free(data);
    }
    return (0);
}
