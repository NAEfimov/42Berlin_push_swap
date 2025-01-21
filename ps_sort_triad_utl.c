/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:57:32 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/21 18:07:22 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

int	calc_opr_a(t_list *a, int len)
{
	int		opr;
	t_list	*b;
	t_list	*c;

	opr = 0;
	if (len > 1)
	{
		b = a->next;
		if (get_int(a) > get_int(b))
			opr = 1;
	}
	if (len > 2)
	{
		c = b->next;
		if (get_int(b) > get_int(c) || (get_int(b) < get_int(c)
				&& get_int(a) > get_int(c)))
			opr += 10;
		if (get_int(a) > get_int(c) && get_int(b) > get_int(c))
			opr += 100;
	}
	return (opr);
}

int	calc_opr_b(t_list *a, int len)
{
	int		opr;
	t_list	*b;
	t_list	*c;

	opr = 0;
	if (len > 1)
	{
		b = a->next;
		if (get_int(a) < get_int(b))
			opr = 1;
	}
	if (len > 2)
	{
		c = b->next;
		if (get_int(b) < get_int(c) || (get_int(b) > get_int(c)
				&& get_int(a) < get_int(c)))
			opr += 10;
		if (get_int(a) < get_int(c) && get_int(b) < get_int(c))
			opr += 100;
	}
	return (opr);
}

void	sort_pair_ss(t_list *lst[LS], int opr_a, int opr_b, char c)
{
	if (opr_a % 10 == 1)
	{
		if (opr_b % 10 == 1)
			ss_lst(lst);
		else
			s_lst(lst, c);
	}
}

void	sort_pair_rr(t_list *lst[LS], int opr_a, int opr_b, char c)
{
	if (opr_a % 10 == 1)
	{
		if (opr_b % 10 == 1)
		{
			r_lst_ab(lst);
			ss_lst(lst);
			rr_lst_ab(lst);
		}
		else
		{
			r_lst(lst, c);
			s_lst(lst, c);
			rr_lst(lst, c);
		}
	}
}
