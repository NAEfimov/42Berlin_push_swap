/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:48:51 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/13 19:08:51 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

void	r_lst(t_list **lst, char c)
{
	t_list	*first;
	t_list	*second;

	first = *lst;
	if (first->next)
	{
		second = first->next;
		ft_lstadd_back(lst, first);
		first->next = NULL;
		*lst = second;
	}
	if (c != ' ')
	{
		write(1, "r", 1);
		write(1, &c, 1);
	}
	if (c != 'r')
		write(1, "\n", 1);
}

void	r_lst_ab(t_list **lst_a, t_list **lst_b)
{
	r_lst(lst_a, 'r');
	r_lst(lst_b, ' ');
}

void	rr_lst(t_list **lst, char c)
{
	t_list	*last;
	t_list	*pre_last;

	pre_last = *lst;
	if (pre_last->next)
	{
		last = pre_last->next;
		while (last->next)
		{
			pre_last = last;
			last = pre_last->next;
		}
		pre_last->next = NULL;
		ft_lstadd_front(lst, last);
	}
	if (c != ' ')
	{	
		write(1, "rr", 2);
		write(1, &c, 1);
	}
	if (c != 'r')
		write(1, "\n", 1);
}

void	rr_lst_ab(t_list **lst_a, t_list **lst_b)
{
	rr_lst(lst_a, 'r');
	rr_lst(lst_b, ' ');
}

void	s_lst(t_list **lst, char c)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!lst || !(*lst)->next)
		return ;
	first = *lst;
	second = (*lst)->next;
	third = second->next;
	second->next = first;
	first->next = third;
	*lst = second;
	if (c != ' ')
	{
		write(1, "s", 1);
		write(1, &c, 1);
	}
	if (c != 's')
		write(1, "\n", 1);
}

void	ss_lst(t_list **lst_a, t_list **lst_b)
{
	s_lst(lst_a, 's');
	s_lst(lst_b, ' ');
}

void	p_lst(t_list **lst_a, t_list **lst_b, char c)
{
	t_list	*node;

	node = *lst_a;
	*lst_a = (*lst_a)->next;
	ft_lstadd_front(lst_b, node);
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}
