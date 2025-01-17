/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:48:51 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/17 17:00:08 by nefimov          ###   ########.fr       */
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

void	r_lst_ab(t_list *lst[3])
{
	t_list	*first;
	t_list	*second;

	first = lst[A];
	if (first->next)
	{
		second = first->next;
		ft_lstadd_back(&lst[A], first);
		first->next = NULL;
		lst[A] = second;
	}
	first = lst[B];
	if (first->next)
	{
		second = first->next;
		ft_lstadd_back(&lst[B], first);
		first->next = NULL;
		lst[B] = second;
	}
	write(1, "rr\n", 3);
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

void	s_lst_pair(t_list **lst_a, t_list **lst_b)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (*lst_a && (*lst_a)->next)
	{
		if (get_int(*lst_a) > get_int((*lst_a)->next))
			a = 1;	
	}
	if (*lst_b && (*lst_b)->next)
	{
		if (get_int(*lst_b) < get_int((*lst_b)->next))
			b = 1;	
	}
	if (a && b)
		ss_lst(lst_a, lst_b);
	else if (a)
		s_lst(lst_a, 'a');
	else if (b)
		s_lst(lst_b, 'b');		
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
