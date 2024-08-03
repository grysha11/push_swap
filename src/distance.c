/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:45:35 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/03 13:45:30 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *p, int *p2)
{
	int	temp;

	temp = *p;
	*p = *p2;
	*p2 = temp;
}

static int	ft_partition(int *arr, int low, int high)
{
	int	flag;
	int	i;
	int	j;

	flag = arr[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] < flag)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	ft_qsort(int *arr, int low, int high)
{
	int	p;

	if (low < high)
	{
		p = ft_partition(arr, low, high);
		ft_qsort(arr, low, p - 1);
		ft_qsort(arr, p + 1, high);
	}
}

int	find_position(t_list **stack, int distance)
{
	int		position;
	t_list	*temp;

	position = 0;
	temp = *stack;
	while (temp != NULL)
	{
		if (temp->distance == distance)
			return (position);
		position++;
		temp = temp->next;
	}
	return (-1);
}
