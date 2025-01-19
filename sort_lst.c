/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:52:28 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/19 22:04:23 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

void	return_numbers(t_list *lst[4])
{
	int	*cmd;

	cmd = get_cmd(&lst[CMD]);
	if (cmd[0] == AR)
		while (cmd[1]-- > 0)
			p_lst(lst, 'b');
	else
		while (cmd[1]-- > 0)
			p_lst(lst, 'a');
	del_int(cmd);
}

// For A
void	sort_pair_a(t_list *lst[4], int len_a, int len_b)
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

void	sort_pair_b(t_list *lst[4], int len_a, int len_b)
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

void	sort_lst(t_list *lst[4], int len, int to_btm)
{
	int		*cmd;

	lst[CMD] = NULL;
	init_cmd(&lst[CMD], len);
	divide_a_init(lst, to_btm, len / 10 + 1);
	while (lst[CMD])
	{
		cmd = read_cmd(lst[CMD]);
		if (cmd[0] == A)
			divide_a(lst);
		else if (cmd[0] == B)
			divide_b(lst);
		else
			return_numbers(lst);
	}
	ft_lstclear(&lst[CMD], del_int);
}
