/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc <hzakharc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:26:34 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/04 20:27:08 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_data(char **data)
{
	free_matrix_data(data);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	error_stack(t_list **stack_a, t_list **stack_b)
{
	ft_lst_clear(stack_a);
	ft_lst_clear(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit (1);
}
