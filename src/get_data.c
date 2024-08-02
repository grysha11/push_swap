/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:58:53 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/01 20:30:55 by hzakharc         ###   ########.fr       */
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
			print_error();
	}
	result = ft_atoi(s);
	if (result < INT_MIN || result > INT_MAX)
		print_error();
	return ((int)result);
}

void	get_data(char **av, int ac, t_list **stack_a)
{
	int		i;
	int		value;
	char	**data;
	t_list	*tmp;
	int		size;

	i = 1;
	size = 0;
	data = matrix_copy(av);
	if (ac == 2)
		i = data_util(&data);
	while (data[size] != NULL)
		size++;
	while (i < size)
	{
		value = check_string(data[i]);
		tmp = ft_list_new(value, i);
		if (!tmp)
			print_error();
		ft_lst_add_back(stack_a, tmp);
		tmp = tmp->next;
		i++;
	}
	for (int j = 0; data[j] != NULL; j++)
        free(data[j]);
    free(data);
}

void check_for_dup(t_list **stack_a)
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
                print_error();
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

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

void	calc_distance(t_list **stack_a)
{
	int 	*sorted;
	int		i;
	t_list	*temp;

	sorted = malloc(sizeof(int) * ft_lst_size(*stack_a));
	if (!sorted)
		print_error();
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
