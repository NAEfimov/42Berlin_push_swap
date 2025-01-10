/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:50:41 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/10 15:51:12 by nefimov          ###   ########.fr       */
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
