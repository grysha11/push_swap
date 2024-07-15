/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:03:19 by hzakharc          #+#    #+#             */
/*   Updated: 2024/07/15 15:41:06 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_list **stack_a)
{
	if (ft_rotate(stack_a) == -1)
		return (-1);
	ft_printf("ra\n");
	return (0);
}
int	rb(t_list **stack_b)
{
	if (ft_rotate(stack_b) == -1)
		return(-1);
	ft_printf("rb\n");
	return (0);
}
int	rr(t_list **stack_a, t_list **stack_b)
{
	if (ft_rotate(stack_a) == -1 || ft_rotate(stack_b) == -1)
		return (-1);
	ft_printf("rr\n");
	return (0);
}
