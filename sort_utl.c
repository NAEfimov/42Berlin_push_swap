/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:50:41 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/13 10:44:01 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

int	lst_is_sorted_down(t_list *lst, int n)
{
	t_list	*c_node;
	t_list	*n_node;

	if (!lst || !lst->next || n < 2)
		return (1);
	c_node = lst;
	n_node = c_node->next;
	while (n_node && (n >= 2))
	{
		if (get_int(c_node) > get_int(n_node))
			return (0);
		c_node = n_node;
		n_node = n_node->next;
		n--;
	}
	return (1);
}

int	lst_is_sorted_up(t_list *lst, int n)
{
	t_list	*c_node;
	t_list	*n_node;

	if (!lst || !lst->next || n < 2)
		return (1);
	c_node = lst;
	n_node = c_node->next;
	while (n_node && (n >= 2))
	{
		if (get_int(c_node) < get_int(n_node))
			return (0);
		c_node = n_node;
		n_node = n_node->next;
		n--;
	}
	return (1);
}

static void	init_m(t_list *lst, int size, int mm[4])
{
	int		i;
	int		num;

	i = -1;
	while (++i < size)
	{
		num = get_int(lst);
		if (num > mm[1])
			mm[0] = num;
		if (num < mm[3])
			mm[2] = num;
		lst = lst->next;
	}
}

// Get median value of first <size> nodes in list <lst>
// mm[4](min_max[4]): <curr_min> <next min> <curr_max> <next_max> 
int	get_mvalue(t_list *lst, int *cmd)
{
	t_list	*node;
	int		i;
	int		j;
	int		mm[4];

	mm[1] = INT_MIN;
	mm[3] = INT_MAX;
	i = -1;
	while (++i <= cmd[1] / 2)
	{
		node = lst;
		j = -1;
		init_m(lst, cmd[1], mm);
		while (++j < cmd[1])
		{
			if (get_int(node) > mm[1] && get_int(node) < mm[0])
				mm[0] = get_int(node);
			if (get_int(node) < mm[3] && get_int(node) > mm[2])
				mm[2] = get_int(node);
			node = node->next;
		}
		// printf("i:%i) m[0]: %i, m[2] %i\n", i, mm[0], mm[2]);
		mm[1] = mm[0];
		mm[3] = mm[2];
	}
	if (cmd[0] == A)
		return (mm[0]);
	else
	 	return (mm[2]);
}
