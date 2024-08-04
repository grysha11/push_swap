/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc <hzakharc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:23:44 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/04 20:58:23 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_distance(t_list **stack_a, int *arr)
{
	t_list	*temp;
	int		i;

	temp = *stack_a;
	while (temp != NULL)
	{
		i = 0;
		while (temp->value != arr[i])
			i++;
		temp->distance = i;
		temp = temp->next;
	}
}

void	calc_distance(t_list **stack_a, t_list **stack_b)
{
	int		*sorted;
	int		i;
	t_list	*temp;

	sorted = malloc(sizeof(int) * ft_lst_size(*stack_a));
	if (!sorted)
		error_stack(stack_a, stack_b);
	temp = *stack_a;
	i = 0;
	while (temp != NULL)
	{
		sorted[i] = temp->value;
		temp = temp->next;
		i++;
	}
	ft_qsort(sorted, 0, ft_lst_size(*stack_a) - 1);
	assign_distance(stack_a, sorted);
	free(sorted);
}

int	data_util(char ***data)
{
	int		j;

	j = 0;
	while ((*data)[1][j] != '\0' && (*data)[1][j] != ' ')
		j++;
	if ((*data)[1][j] == '\0')
		return (1);
	else
		return (0);
}
