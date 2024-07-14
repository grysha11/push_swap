/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:13:33 by hzakharc          #+#    #+#             */
/*   Updated: 2024/07/14 00:44:27 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *ft_list_new(int value, int index)
{
    t_list  *head;

    head = malloc(sizeof(t_list));
    if (!head)
        return (NULL);
    head->value = value;
    head->index = index;
    head->next = NULL;
    return (head);
}

void    ft_lst_add_front(t_list **lst, t_list *new_node)
{
    if (!new_node)
        return ;
    new_node->next = *lst;
    *lst = new_node;
}

void    ft_lst_add_back(t_list **lst, t_list *new_node)
{
    t_list	*tmp;

    if (!new_node)
        return ;
    if (*lst == NULL)
        *lst = new_node;
    else
    {
        tmp = *lst;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new_node;
    }
}

void	ft_lst_clear(t_list **lst)
{
	t_list	*head;

	while (*lst)
	{
		head = (*lst)->next;
		free(*lst);
		(*lst) = head;
	}
}

t_list	*ft_lst_last(t_list *head)
{
	t_list *tmp;

	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
