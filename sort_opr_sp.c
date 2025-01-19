/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opr_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:19:25 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/19 21:20:04 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

void	s_lst_make(t_list **lst)
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
}

void	s_lst(t_list *lst[4], char c)
{
	int		i;
	char	*str;
	t_list	*node;

	i = c - 'a';
	s_lst_make(&lst[i]);
	if (c == 'a')
		str = "sa\n";
	else
		str = "sb\n";
	node = ft_lstnew((void *)ft_strdup(str));
	ft_lstadd_back(&lst[OUT], node);
}

void	ss_lst(t_list *lst[4])
{
	t_list	*node;

	s_lst_make(&lst[A]);
	s_lst_make(&lst[B]);
	node = ft_lstnew((void *)ft_strdup("ss\n"));
	ft_lstadd_back(&lst[OUT], node);
}

void	s_lst_pair(t_list *lst[4])
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (lst[A] && lst[A]->next)
	{
		if (get_int(lst[A]) > get_int(lst[A]->next))
			a = 1;
	}
	if (lst[B] && lst[B]->next)
	{
		if (get_int(lst[B]) < get_int(lst[B]->next))
			b = 1;
	}
	if (a && b)
		ss_lst(lst);
	else if (a)
		s_lst(lst, 'a');
	else if (b)
		s_lst(lst, 'b');
}

void	p_lst(t_list *lst[4], char c)
{
	t_list	*node;
	t_list	**lst_a;
	t_list	**lst_b;
	char	*str;

	if (c == 'a')
	{
		lst_a = &lst[B];
		lst_b = &lst[A];
	}
	else
	{
		lst_a = &lst[A];
		lst_b = &lst[B];
	}
	node = *lst_a;
	*lst_a = (*lst_a)->next;
	ft_lstadd_front(lst_b, node);
	if (c == 'a')
		str = "pa\n";
	else
		str = "pb\n";
	node = ft_lstnew((void *)ft_strdup(str));
	ft_lstadd_back(&lst[OUT], node);
}
