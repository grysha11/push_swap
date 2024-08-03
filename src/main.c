/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:14:45 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/03 15:28:45 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_list **stack_a, t_list **stack_b, int ac)
{
	if (ac == 3)
		sort2(stack_a);
	else if (ac == 4)
		sort3(stack_a);
	else if (ac == 5)
		sort4(stack_a, stack_b);
	else if (ac == 6)
		sort5(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac < 2)
		return (0);
	init_stacks(ac, av, &stack_a, &stack_b);
	if (is_sorted(&stack_a) == 0)
	{
		ft_lst_clear(&stack_a);
		return (0);
	}
	if (ac <= 6)
		simple_sort(&stack_a, &stack_b, ac);
	else
		butterfly_sort(&stack_a, &stack_b, ac);
	ft_lst_clear(&stack_a);
	ft_lst_clear(&stack_b);
	return (0);
}
