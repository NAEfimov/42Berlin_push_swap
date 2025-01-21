/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opr_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:05:27 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/21 12:19:30 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

// Shift down elements
static void	rr_lst_make(t_list **lst)
{
	t_list	*last;
	t_list	*pre_last;

	pre_last = *lst;
	if (pre_last && pre_last->next)
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

// Shift down all elements of stack 'c'
void	rr_lst(t_list *lst[LS], char c)
{
	int		i;
	char	*str;

	i = c - 'a';
	rr_lst_make(&lst[i]);
	if (c == 'a')
		str = "rra\n";
	else
		str = "rrb\n";
	add_opr_out(lst, str);
}

// Shift down all elements of both stacks
void	rr_lst_ab(t_list *lst[LS])
{
	rr_lst_make(&lst[A]);
	rr_lst_make(&lst[B]);
	add_opr_out(lst, "rrr\n");
}
