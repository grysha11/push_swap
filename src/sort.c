/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:22:31 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/01 16:40:02 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	form_butterfly(t_list **stack_a, t_list **stack_b)
{
	int		counter;
	
	counter = 1;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->distance <= counter)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			counter++;
		}
		else if ((*stack_a)->distance <= counter + 1)
		{
			pb(stack_a, stack_b);
			counter++;
		}
		else
			ra(stack_a);
	}
}
