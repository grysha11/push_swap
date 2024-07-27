/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:17:55 by hzakharc          #+#    #+#             */
/*   Updated: 2024/07/22 13:34:12 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_list **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
	else
		return ;
}

int	find_min(t_list **stack)
{
	t_list	*temp;
	int		min_index;
	int		i;
	int		min_value;

	temp = *stack;
	i = 0;
	min_index = 0;
	min_value = temp->value;
	while (temp->next != NULL)
	{
		i++;
		temp = temp->next;
		if (temp->value < min_value)
		{
			min_value = temp->value;
			min_index = i;
		}
	}
	return (min_index);
}

void	sort3(t_list **stack_a)
{
	if (is_sorted(stack_a) == 0)
		return ;
	else if (find_min(stack_a) == 0)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (find_min(stack_a) == 1)
	{
		if ((*stack_a)->value < (*stack_a)->next->next->value)
			sa(stack_a);
		else
			ra(stack_a);
	}
	else
	{
		if ((*stack_a)->value < (*stack_a)->next->value)
			rra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}

void	sort4(t_list **stack_a, t_list **stack_b)
{
	if (find_min(stack_a) == 1)
		sa(stack_a);
	else if (find_min(stack_a) == 2)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (find_min(stack_a) == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort3(stack_a);
	pa(stack_a, stack_b);
}

void	sort5(t_list **stack_a, t_list **stack_b)
{
	if (find_min(stack_a) == 1)
		sa(stack_a);
	else if (find_min(stack_a) == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (find_min(stack_a) == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (find_min(stack_a) == 4)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort4(stack_a, stack_b);
	pa(stack_a, stack_b);
}
