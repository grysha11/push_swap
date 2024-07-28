/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:14:45 by hzakharc          #+#    #+#             */
/*   Updated: 2024/07/27 21:22:58 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
    t_list  *stack_a;
    t_list  *stack_b;

    stack_a = init_stack_a(ac, av);
    stack_b = NULL;
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
    ft_lst_clear(&stack_a);
    return (0);
}
