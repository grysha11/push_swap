/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:56:46 by hzakharc          #+#    #+#             */
/*   Updated: 2024/07/15 14:58:17 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_list **stack_a)
{
	if (ft_rrotate(stack_a) == -1)
		return (-1);
	ft_printf("rra\n");
	return (0);
}
int	rrb(t_list **stack_b)
{
	if (ft_rrotate(stack_b) == -1)
		return (-1);
	ft_printf("rrb\n");
	return (0);
}
int rrr(t_list **stack_a, t_list **stack_b)
{
	if (ft_rrotate(stack_a) == -1 || ft_rrotate(stack_b))
		return (-1);
	ft_printf("rrr\n");
	return (0);	
}
