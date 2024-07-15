/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:14:45 by hzakharc          #+#    #+#             */
/*   Updated: 2024/07/15 15:46:24 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
    t_list  *stack_a;
    t_list  *current;


    if (ac != 1)
    {
        stack_a = init_stack_a(ac, av);
        ft_rrotate(&stack_a);
        current = stack_a;
        while (current != NULL)
        {
            printf("Value is: %d\tIndex is: %d\n", current->value, current->index);
            current = current->next;
        }
        while (stack_a != NULL)
        {
            t_list *tmp = stack_a->next;
            free(stack_a);
            stack_a = tmp; 
        }
    }
    else
        print_error();

    return (0);
}
