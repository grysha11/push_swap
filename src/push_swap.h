/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:15:54 by hzakharc          #+#    #+#             */
/*   Updated: 2024/07/15 15:41:45 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../include/ft_printf/ft_printf.h"
# include "../include/libft/libft.h"

typedef struct	s_list
{
    int				value;
    int				index;
    struct s_list	*next;
}					t_list;

void	print_error(void);
t_list	*init_stack_a(int ac, char **av);

t_list  *ft_list_new(int value, int index);
void    ft_lst_add_back(t_list **lst, t_list *new_node);
void    ft_lst_add_front(t_list **lst, t_list *new_node);
void	ft_lst_clear(t_list **lst);
t_list	*ft_lst_last(t_list *head);
int	    ft_lst_size(t_list *lst);

int	ft_push(t_list **src, t_list **dst);
int	ft_swap(t_list **stack);
int	ft_rotate(t_list **lst);
int	ft_rrotate(t_list **lst);

int	pa(t_list **stack_a, t_list **stack_b);
int	pb(t_list **stack_a, t_list **stack_b);
int	sa(t_list **stack_a);
int	sb(t_list **stack_b);
int	ss(t_list **stack_a, t_list	**stack_b);
int	ra(t_list **stack_a);
int	rb(t_list **stack_b);
int	rr(t_list **stack_a, t_list **stack_b);
int	rra(t_list **stack_a);
int	rrb(t_list **stack_b);
int rrr(t_list **stack_a, t_list **stack_b);

int		check_string(char *s);
void    get_data(char **av, int ac, t_list **stack_a);

#endif