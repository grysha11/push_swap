/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:11:18 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/01 20:31:28 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

t_list	*init_stack_a(int ac, char **av)
{
	t_list	*stack_a;

	stack_a = NULL;
	get_data(av, ac, &stack_a);
	check_for_dup(&stack_a);
	calc_distance(&stack_a);
	return (stack_a);
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

char	**matrix_copy(char **av)
{
	size_t	i = 0;
	size_t	j = 0;
	char	**result;
	
	while (av[i] != NULL)
		i++;
	result = malloc(sizeof(char *) * (i + 1));
	if (!result)
		print_error();
	result[i] = NULL;
	i = 0;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != '\0')
			j++;
		result[i] = malloc(sizeof(char) * (j + 1));
		if (!result[i])
			print_error();
		result[i][j] = '\0';
		i++;
	}
	i = 0;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			result[i][j] = av[i][j];
			j++;
		}
		i++;
	}
	return (result);
}

int data_util(char ***data)
{
    char **temp;
    size_t j = 0;

    while ((*data)[1][j] != '\0' && (*data)[1][j] != ' ')
        j++;
    if ((*data)[1][j] == '\0')
        return 1;
    else
    {
        temp = ft_split((*data)[1], ' ');
        for (int k = 0; (*data)[k] != NULL; k++)
            free((*data)[k]);
        free(*data);
        *data = temp;
        return 0;
    }
}

