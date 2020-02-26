/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:05:46 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/02/26 19:14:31 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


int main(int argc, char *argv[])
{
    t_stack a;
    t_stack b;

    int num = 4;

    stack_init(&a, 1, sizeof(int));
    stack_init(&b, 1, sizeof(int)); 

    for (int i=0; i < 10; i++)
    {  
        stack_push(&a, &i);
    }

    stack_rotate(&a, NULL);
    for (size_t i=0; i < a.size; i++)
    {  
        printf("%d\n", *(int *)vector_get_element(&a, i));
    }
    printf("\n\n");
    printf("%d\n", stack_is_sorted(&a));
    return (0);
}
