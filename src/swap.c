/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 12:49:27 by hzakharc          #+#    #+#             */
/*   Updated: 2024/07/14 13:19:17 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack)
{
	t_list	*tmp;
	t_list	*head;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	head = (*stack)->next;
	tmp = (*stack)->next->next;
	head->next = *stack;
	(*stack)->next = tmp;
	*stack = head;
}

void	sa(t_list **stack_a)
{
	ft_swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_list **stack_b)
{
	ft_swap(stack_b);
	ft_printf("sb\n");
}
void	ss(t_list **stack_a, t_list	**stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("ss\n");
}
