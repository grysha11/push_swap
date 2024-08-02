/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:14:45 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/01 19:54:48 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
    t_list  *stack_a;
    t_list  *stack_b;
    t_list  *temp;

    if (ac < 2)
        return (0);
    stack_a = init_stack_a(ac, av);
    temp = stack_a;
    // while (temp != NULL)
    // {
    //     printf("value is:%d\tindex is:%d\tdistance is:%d\n", temp->value, temp->index, temp->distance);
    //     temp = temp->next;
    // }
    stack_b = NULL;
    if (is_sorted(&stack_a) == 0)
    {
        ft_lst_clear(&stack_a);
        return (0);
    }
    if (ac <= 6)
    {
        if (ac == 3)
            sort2(&stack_a);
        else if (ac == 4)
            sort3(&stack_a);
        else if (ac == 5)
            sort4(&stack_a, &stack_b);
        else if (ac == 6)
            sort5(&stack_a, &stack_b);
    }
    else
    {
        form_butterfly(&stack_a, &stack_b);
        temp = stack_b;
        //printf("STACK_B\n");
        // while (temp != NULL)
        // {
        //     printf("value is:%d\tindex is:%d\tdistance is:%d\n", temp->value, temp->index, temp->distance);
        //     temp = temp->next;
        // }
    }
    ft_lst_clear(&stack_a);
    ft_lst_clear(&stack_b);
    return (0);
}
