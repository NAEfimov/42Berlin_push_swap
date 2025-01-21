/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_triad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:22:46 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/21 19:29:19 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

// Sort three or less elements in stack A simultaneously with stack B
void	sort_pair_a(t_list *lst[LS], int len_a, int len_b)
{
	int	opr_a;
	int	opr_b;

	if (ft_lstsize(lst[A]) < len_a)
		len_a = ft_lstsize(lst[A]);
	if (ft_lstsize(lst[B]) < len_b)
		len_b = ft_lstsize(lst[B]);
	opr_a = calc_opr_a(lst[A], len_a);
	opr_b = calc_opr_b(lst[B], len_b);
	sort_pair_ss(lst, opr_a, opr_b, 'a');
	opr_a = opr_a / 10;
	opr_b = opr_b / 10;
	sort_pair_rr(lst, opr_a, opr_b, 'a');
	opr_a = opr_a / 10;
	opr_b = opr_b / 10;
	sort_pair_ss(lst, opr_a, opr_b, 'a');
}

// Sort three elements in stack A if they are alone in the stack
void	sort_triad_a_alone(t_list *lst[LS])
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = lst[A];
	b = a->next;
	c = b->next;
	if (get_int(a) > get_int(b) && get_int(a) > get_int(c))
		r_lst(lst, 'a');
	a = lst[A];
	b = a->next;
	c = b->next;
	if (get_int(b) > get_int(a) && get_int(b) > get_int(c))
		rr_lst(lst, 'a');
	a = lst[A];
	b = a->next;
	c = b->next;
	if (get_int(a) > get_int(b))
		s_lst(lst, 'a');
}

// Sort three elements in stack B if they are alone in the stack
void	sort_triad_b_alone(t_list *lst[LS])
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = lst[B];
	b = a->next;
	c = b->next;
	if (get_int(a) < get_int(b) && get_int(a) < get_int(c))
		r_lst(lst, 'b');
	a = lst[B];
	b = a->next;
	c = b->next;
	if (get_int(b) < get_int(a) && get_int(b) < get_int(c))
		rr_lst(lst, 'b');
	a = lst[B];
	b = a->next;
	c = b->next;
	if (get_int(a) < get_int(b))
		s_lst(lst, 'b');
}

// Sort three or less elements in stack B simultaneously with stack A
void	sort_pair_b(t_list *lst[LS], int len_a, int len_b)
{
	int	opr_a;
	int	opr_b;

	if (ft_lstsize(lst[A]) < len_a)
		len_a = ft_lstsize(lst[A]);
	if (ft_lstsize(lst[B]) < len_b)
		len_b = ft_lstsize(lst[B]);
	opr_a = calc_opr_a(lst[A], len_a);
	opr_b = calc_opr_b(lst[B], len_b);
	sort_pair_ss(lst, opr_b, opr_a, 'b');
	opr_a = opr_a / 10;
	opr_b = opr_b / 10;
	sort_pair_rr(lst, opr_b, opr_a, 'b');
	opr_a = opr_a / 10;
	opr_b = opr_b / 10;
	sort_pair_ss(lst, opr_b, opr_a, 'b');
}
