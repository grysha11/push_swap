/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:43:20 by hzakharc          #+#    #+#             */
/*   Updated: 2024/07/18 17:16:16 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (ft_push(stack_b, stack_a) == -1)
		return (-1);
	ft_printf("pa\n");
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (ft_push(stack_a, stack_b) == -1)
		return (-1);
	ft_printf("pb\n");
	return (0);
}

int	sa(t_list **stack_a)
{
	if (ft_swap(stack_a) == -1)
		return (-1);
	ft_printf("sa\n");
	return (0);
}

int	sb(t_list **stack_b)
{
	if (ft_swap(stack_b) == -1)
		return (-1);
	ft_printf("sb\n");
	return (0);
}

int	ss(t_list **stack_a, t_list	**stack_b)
{
	if (ft_swap(stack_a) == -1)
		return (-1);
	if (ft_swap(stack_b) == -1)
		return (-1);
	ft_printf("ss\n");
	return (0);
}
