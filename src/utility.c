/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc <hzakharc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:11:18 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/04 20:38:57 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix_data(char **data)
{
	int	i;

	i = 0;
	while (data[i] != NULL)
	{
		free(data[i]);
		i++;
	}
	free(data);
}

int	is_sorted(t_list **stack_a)
{
	t_list	*temp;

	temp = *stack_a;
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (-1);
		temp = temp->next;
	}
	return (0);
}

int	ft_lst_size(t_list *lst)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	matrix_copy_data(char **av, char **data)
{
	int	i;
	int	j;

	i = 0;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			data[i][j] = av[i][j];
			j++;
		}
		i++;
	}
}

char	**matrix_copy(char **av)
{
	size_t	i;
	size_t	j;
	char	**result;

	i = 0;
	while (av[i] != NULL)
		i++;
	result = malloc(sizeof(char *) * (i + 1));
	if (!result)
		error_data(result);
	result[i] = NULL;
	i = 0;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != '\0')
			j++;
		result[i] = malloc(sizeof(char) * (j + 1));
		if (!result[i])
			error_data(result);
		result[i][j] = '\0';
		i++;
	}
	matrix_copy_data(av, result);
	return (result);
}
