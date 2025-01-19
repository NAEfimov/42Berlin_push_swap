/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:48:51 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/19 21:20:01 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

void	r_lst(t_list *lst[4], char c)
{
	t_list	*first;
	t_list	*second;
	int		i;
	char	*str;

	i = c - 'a';
	first = lst[i];
	if (first->next)
	{
		second = first->next;
		ft_lstadd_back(&lst[i], first);
		first->next = NULL;
		lst[i] = second;
	}
	if (c == 'a')
		str = "ra\n";
	else
		str = "rb\n";
	first = ft_lstnew((void *)ft_strdup((const char *)str));
	ft_lstadd_back(&lst[OUT], first);
}

void	r_lst_ab(t_list *lst[4])
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
	first = ft_lstnew((void *)ft_strdup("rr\n"));
	ft_lstadd_back(&lst[OUT], first);
}

void	rr_lst_make(t_list **lst)
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
}

void	rr_lst(t_list *lst[4], char c)
{
	int		i;
	char	*str;
	t_list	*node;

	i = c - 'a';
	rr_lst_make(&lst[i]);
	if (c == 'a')
		str = "rra\n";
	else
		str = "rrb\n";
	node = ft_lstnew((void *)ft_strdup(str));
	ft_lstadd_back(&lst[OUT], node);
}

void	rr_lst_ab(t_list *lst[4])
{
	t_list	*node;

	rr_lst_make(&lst[A]);
	rr_lst_make(&lst[B]);
	node = ft_lstnew((void *)ft_strdup("rrr\n"));
	ft_lstadd_back(&lst[OUT], node);
}
