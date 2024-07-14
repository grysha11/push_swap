/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:11:18 by hzakharc          #+#    #+#             */
/*   Updated: 2024/07/13 19:46:35 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
t_list	*init_stack_a(int ac, char **av)
{
	t_list	*stack_a;

	stack_a = NULL;
	get_data(av, ac, &stack_a);
	return (stack_a);
}