/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:58:53 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/05 12:30:41 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_string(char *s)
{
	size_t	i;
	long	result;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			return (-1);
	}
	result = ft_atol(s);
	if (result < INT_MIN || result > INT_MAX)
		return (-1);
	return (0);
}

int	check_data(char **data, int i)
{
	int	j;

	j = i;
	while (data[j] != NULL)
	{
		if (check_string(data[j]) == -1)
		{
			return (-1);
		}
		j++;
	}
	return (0);
}

void	get_data_util(char **data, int i, t_list **stack_a, t_list **stack_b)
{
	int		value;
	t_list	*tmp;
	int		size;

	size = 0;
	while (data[size] != NULL)
		size++;
	tmp = *stack_a;
	while (i < size)
	{
		value = ft_atol(data[i]);
		tmp = ft_list_new(value);
		if (!tmp)
			error_stack(stack_a, stack_b);
		ft_lst_add_back(stack_a, tmp);
		tmp = tmp->next;
		i++;
	}
	free_matrix_data(data);
}

void	get_data(char **data, int ac, t_list **stack_a, t_list **stack_b)
{
	int		i;
	char	**temp;

	i = 1;
	if (ac == 2)
	{
		if (data_util(&data) == 0)
		{
			temp = ft_split(data[1], ' ');
			if (!temp)
				error_data(data);
			free_matrix_data(data);
			data = temp;
			i = 0;
		}
	}
	if (check_data(data, i) == -1)
		error_data(data);
	get_data_util(data, i, stack_a, stack_b);
}

void	check_for_dup(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *stack_a;
	while (temp->next != NULL)
	{
		temp2 = temp->next;
		while (temp2 != NULL)
		{
			if (temp->value == temp2->value)
				error_stack(stack_a, stack_b);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}
