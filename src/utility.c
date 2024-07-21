/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:11:18 by hzakharc          #+#    #+#             */
/*   Updated: 2024/07/19 20:52:10 by hzakharc         ###   ########.fr       */
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

t_list	*init_stack_b(int ac)
{
	t_list	*stack_b;
	t_list	*temp;
	int		i;

	i = 1;
	stack_b = malloc(sizeof(t_list));
	if (!stack_b)
		return (NULL);
	temp = stack_b;
	while (i < ac)
	{
		temp->next = malloc(sizeof(t_list));
		if (!temp->next)
			return (NULL);
		temp = temp->next;
		i++;
	}
	temp->next = NULL;
	return (stack_b);
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
