/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:15:54 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/03 15:48:23 by hzakharc         ###   ########.fr       */
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

typedef struct s_list
{
	int				value;
	int				distance;
	struct s_list	*next;
}					t_list;

void	error_data(char **data);
void	error_stack(t_list **stack_a, t_list **stack_b);
void	init_stacks(int ac, char **av, t_list **stack_a, t_list **stack_b);
void	free_matrix_data(char **data);

t_list	*ft_list_new(int value);
void	ft_lst_add_back(t_list **lst, t_list *new_node);
void	ft_lst_add_front(t_list **lst, t_list *new_node);
void	ft_lst_clear(t_list **lst);
t_list	*ft_lst_last(t_list *head);
int		ft_lst_size(t_list *lst);

int		ft_push(t_list **src, t_list **dst);
int		ft_swap(t_list **stack);
int		ft_rotate(t_list **lst);
int		ft_rrotate(t_list **lst);

int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_a, t_list **stack_b);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list	**stack_b);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);

int		find_min(t_list **stack);
void	ft_qsort(int *arr, int low, int high);
int		is_sorted(t_list **stack_a);
void	sort2(t_list **stack_a);
void	sort3(t_list **stack_a);
void	sort4(t_list **stack_a, t_list **stack_b);
void	sort5(t_list **stack_a, t_list **stack_b);

void	butterfly_sort(t_list **stack_a, t_list **stack_b, int ac);
void	form_butterfly(t_list **stack_a, t_list **stack_b, int ac);
void	reform_butterfly(t_list **stack_b);
int		find_position(t_list **stack, int distance);
int		find_max_distance(t_list **stack);
int		find_max_distance(t_list **stack);
int		optimize(int ac);

int		check_string(char *s);
int		data_util(char ***data);
char	**matrix_copy(char **av);
void	get_data(char **data, int ac, t_list **stack_a, t_list **stack_b);
void	check_for_dup(t_list **stack_a, t_list **stack_b);
void	calc_distance(t_list **stack_a, t_list **stack_b);

#endif