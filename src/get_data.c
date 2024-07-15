/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:22:54 by hzakharc          #+#    #+#             */
/*   Updated: 2024/07/15 15:44:32 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_string(char *s)
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
	size_t	i;
	int		value;
	t_list	*tmp;
	
	i = 1;
	while (i < ac)
	{
		value = check_string(av[i]);
		tmp = ft_list_new(value, i);
		if (!tmp)
			print_error();
		ft_lst_add_back(stack_a, tmp);
		tmp = tmp->next;
		i++;
	}
}
