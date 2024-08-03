/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:11:18 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/03 15:44:45 by hzakharc         ###   ########.fr       */
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

void	error_data(char **data)
{
	free_matrix_data(data);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	error_stack(t_list **stack_a, t_list **stack_b)
{
	ft_lst_clear(stack_a);
	ft_lst_clear(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

void	init_stacks(int ac, char **av, t_list **stack_a, t_list **stack_b)
{
	char	**data;

	stack_a = NULL;
	stack_b = NULL;
	data = matrix_copy(av);
	if (!data)
		error_data(data);
	get_data(data, ac, stack_a, stack_b);
	check_for_dup(stack_a, stack_b);
	calc_distance(stack_a, stack_b);
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
	size_t	i = 0;
	size_t	j = 0;
	char	**result;
	
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

int data_util(char ***data)
{
    char	**temp;
    int		j;

	j = 0;
    while ((*data)[1][j] != '\0' && (*data)[1][j] != ' ')
        j++;
    if ((*data)[1][j] == '\0')
        return 1;
    else
    {
        temp = ft_split((*data)[1], ' ');
		free_matrix_data(*data);
        *data = temp;
        return 0;
    }
}

