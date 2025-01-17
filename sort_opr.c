/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:48:51 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/17 18:36:22 by nefimov          ###   ########.fr       */
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
	// write(1, "r", 1);
	// write(1, &c, 1);
	// write(1, "\n", 1);
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
	// write(1, "rr\n", 3);
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
	// write(1, "rr", 2);
	// write(1, &c, 1);
	// write(1, "\n", 1);
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
	// write(1, "rrr\n", 4);
	node = ft_lstnew((void *)ft_strdup("rrr\n"));
	ft_lstadd_back(&lst[OUT], node);
}

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
	// write(1, "s", 1);
	// write(1, &c, 1);
	// write(1, "\n", 1);
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
	// write(1, "ss\n", 3);
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


	if ( c == 'a')
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
	// write(1, "p", 1);
	// write(1, &c, 1);
	// write(1, "\n", 1);
	if (c == 'a')
		str = "pa\n";
	else
		str = "pb\n";
	node = ft_lstnew((void *)ft_strdup(str));
	ft_lstadd_back(&lst[OUT], node);
}
