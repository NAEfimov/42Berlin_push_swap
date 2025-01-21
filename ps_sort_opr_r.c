/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opr_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:48:51 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/21 12:18:57 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

// Shift up elements
static void	r_lst_make(t_list *lst[LS], int stack)
{
	t_list	*first;
	t_list	*second;

	first = lst[stack];
	if (first && first->next)
	{
		second = first->next;
		ft_lstadd_back(&lst[stack], first);
		first->next = NULL;
		lst[stack] = second;
	}
}

// Shift up all elements of stack 'c'
void	r_lst(t_list *lst[LS], char c)
{
	char	*str;

	r_lst_make(lst, (c - 'a'));
	if (c == 'a')
		str = "ra\n";
	else
		str = "rb\n";
	add_opr_out(lst, str);
}

// Shift up all elements in both stacks
void	r_lst_ab(t_list *lst[LS])
{
	r_lst_make(lst, A);
	r_lst_make(lst, B);
	add_opr_out(lst, "rr\n");
}
