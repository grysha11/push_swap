/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc <hzakharc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:22:31 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/04 22:37:14 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	butterfly_sort(t_list **stack_a, t_list **stack_b)
{
	form_butterfly(stack_a, stack_b);
	while ((*stack_b)->next != NULL)
	{
		reform_butterfly(stack_b);
		pa(stack_a, stack_b);
	}
	pa(stack_a, stack_b);
}

void	form_butterfly(t_list **stack_a, t_list **stack_b)
{
	int		counter;
	int		n;

	counter = 1;
	n = optimize(stack_a);
	while (*stack_a != NULL)
	{
		if ((*stack_a)->distance <= counter)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			counter++;
		}
		else if ((*stack_a)->distance <= counter + n)
		{
			pb(stack_a, stack_b);
			counter++;
		}
		else
			ra(stack_a);
	}
}

void	reform_butterfly(t_list **stack_b)
{
	int	max;
	int	size;

	max = find_max_distance(stack_b);
	size = ft_lst_size(*stack_b);
	while ((*stack_b)->distance != max)
	{
		if (find_position(stack_b, max) <= size / 2)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}

int	find_max_distance(t_list **stack)
{
	int		max;
	t_list	*temp;

	temp = *stack;
	if (temp == NULL)
		return (0);
	max = temp->distance;
	while (temp != NULL)
	{
		if (temp->distance > max)
			max = temp->distance;
		temp = temp->next;
	}
	return (max);
}

int	optimize(t_list **stack_a)
{
	int	count;

	count = ft_lst_size(*stack_a);
	if (count > 450)
		return (29);
	if (count >= 343)
		return (26);
	if (count >= 235)
		return (21);
	if (count >= 127)
		return (18);
	if (count >= 83)
		return (15);
	if (count >= 62)
		return (7);
	if (count >= 41)
		return (4);
	if (count > 5)
		return (1);
	return (1);
}
