/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:14:45 by hzakharc          #+#    #+#             */
/*   Updated: 2024/07/27 18:15:14 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
    t_list  *stack_a;
    t_list  *stack_b;
    t_list  *current;
    t_list  *current2;


    if (ac != 1)
    {
        stack_a = init_stack_a(ac, av);
        stack_b = init_stack_b(ac);
        current = stack_a;
        while (current != NULL)
        {
            printf("Value is: %d\tIndex is: %d\tDistance is: %d\n", current->value, current->index, current->distance);
            current = current->next;
        }
        sort5(&stack_a, &stack_b);
        current = stack_a;
        printf("\n");
        while (current != NULL)
        {
            printf("Value is: %d\tIndex is: %d\tDistance is: %d\n", current->value, current->index, current->distance);
            current = current->next;
        }
        while (stack_a != NULL)
        {
            t_list *tmp = stack_a->next;
            free(stack_a);
            stack_a = tmp; 
        }
        while (stack_b != NULL)
        {
            t_list *tmp = stack_b->next;
            free(stack_b);
            stack_b = tmp;
        }
    }
    else
        print_error();
    return (0);
}
