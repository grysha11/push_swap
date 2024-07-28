/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:41:10 by hzakharc          #+#    #+#             */
/*   Updated: 2024/07/27 21:23:34 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push(t_list **src, t_list **dst)
{
	t_list	*temp;
	t_list	*tsrc;
	t_list	*tdst;

	if (ft_lst_size(*src) == 0)
		return (-1);
	tdst = *dst;
	tsrc = *src;
	temp = tsrc;
	tsrc = tsrc->next;
	*src = tsrc;
	if (!tdst)
	{
		tdst = temp;
		tdst->next = NULL;
		*dst = tdst;
	}
	else
	{
		temp->next = tdst;
		*dst = temp;
	}
	return (0);
}

int	ft_swap(t_list **stack)
{
	t_list	*tmp;
	t_list	*head;

	if (*stack == NULL || (*stack)->next == NULL)
		return (-1);
	head = *stack;
	tmp = head->next;
	head->next = tmp->next;
	tmp->next = head;
	*stack = tmp;
	return (0);
}

int	ft_rotate(t_list **lst)
{
	t_list	*head;
	t_list	*end;

	if (ft_lst_size(*lst) < 2)
		return (-1);
	head = *lst;
	end = ft_lst_last(*lst);
	*lst = head->next;
	head->next = NULL;
	end->next = head;
	return (0);
}

int	ft_rrotate(t_list **lst)
{
	t_list	*head;
	t_list	*end;

	if (ft_lst_size(*lst) < 2)
		return (-1);
	end = *lst;
	while (end->next->next != NULL)
		end = end->next;
	head = end->next;
	end->next = NULL;
	head->next = *lst;
	*lst = head;
	return (0);
}
