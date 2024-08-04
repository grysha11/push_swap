/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc <hzakharc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:14:45 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/04 22:36:52 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(int ac, char **av, t_list **stack_a, t_list **stack_b)
{
	char	**data;

	data = matrix_copy(av);
	if (!data)
		error_data(data);
	get_data(data, ac, stack_a, stack_b);
	check_for_dup(stack_a, stack_b);
	calc_distance(stack_a, stack_b);
}

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lst_size(*stack_a) == 2)
		sort2(stack_a);
	else if (ft_lst_size(*stack_a) == 3)
		sort3(stack_a);
	else if (ft_lst_size(*stack_a) == 4)
		sort4(stack_a, stack_b);
	else if (ft_lst_size(*stack_a) == 5)
		sort5(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	init_stacks(ac, av, &stack_a, &stack_b);
	if (is_sorted(&stack_a) == 0)
	{
		ft_lst_clear(&stack_a);
		return (0);
	}
	if (ft_lst_size(stack_a) < 6)
		simple_sort(&stack_a, &stack_b);
	else
		butterfly_sort(&stack_a, &stack_b);
	ft_lst_clear(&stack_a);
	ft_lst_clear(&stack_b);
	return (0);
}
