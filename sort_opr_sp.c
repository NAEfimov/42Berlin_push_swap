/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opr_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:19:25 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/21 13:11:49 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

// Swap the first 2 elements
static void	s_lst_make(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (lst && *lst && (*lst)->next)
	{	
		first = *lst;
		second = (*lst)->next;
		third = second->next;
		second->next = first;
		first->next = third;
		*lst = second;
	}
}

// Swap the first 2 elements at the top of stack 'c'
void	s_lst(t_list *lst[LS], char c)
{
	char	*str;

	s_lst_make(&lst[c - 'a']);
	if (c == 'a')
		str = "sa\n";
	else
		str = "sb\n";
	add_opr_out(lst, str);
}

// Swap the first 2 elements at the top of both stacks
void	ss_lst(t_list *lst[LS])
{
	s_lst_make(&lst[A]);
	s_lst_make(&lst[B]);
	add_opr_out(lst, "ss\n");
}

// Check if we can swap first 2 elements in both stacks
void	s_lst_pair(t_list *lst[LS])
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

// Take the first element at the top of one stack 
// and put it at the top of another
void	p_lst(t_list *lst[LS], char c)
{
	t_list	*node;
	t_list	**lst_a;
	t_list	**lst_b;
	char	*str;

	lst_a = &lst[(c - 'a' + 1) % 2];
	lst_b = &lst[(c - 'a') % 2];
	if (lst_a && *lst_a)
	{
		node = *lst_a;
		*lst_a = (*lst_a)->next;
		ft_lstadd_front(lst_b, node);
	}
	if (c == 'a')
		str = "pa\n";
	else
		str = "pb\n";
	add_opr_out(lst, str);
}
