/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_lst_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:17:26 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/19 21:17:39 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

void	init_move_btn(t_list *lst[4], int *rr_back, int *to_move)
{
	p_lst(lst, 'b');
	if ((lst[B])->next)
		(*rr_back)++;
	(*to_move)--;
}

void	init_move_top(t_list *lst[4], int *rr_back, int *to_move)
{
	while (*rr_back > 0)
	{
		r_lst(lst, 'b');
		(*rr_back)--;
	}
	p_lst(lst, 'b');
	(*to_move)--;
}

int	divide_a_move_init(t_list *lst[4], int to_move, int m, int m_btm)
{
	int	rr_back;

	rr_back = 0;
	while (to_move > 0)
	{
		if (get_int(lst[A]) < m)
		{
			if (get_int(lst[A]) < m_btm)
				init_move_btn(lst, &rr_back, &to_move);
			else
				init_move_top(lst, &rr_back, &to_move);
		}
		else
		{
			if (rr_back > 0)
			{
				r_lst_ab(lst);
				rr_back--;
			}
			else
				r_lst(lst, 'a');
		}
	}
	return (rr_back);
}

void	divide_a_third_init(t_list *lst[4], int *cmd, int to_btm, int to_top)
{
	int	m;
	int	m_btm;
	int	to_move;
	int	rr_back;

	to_move = (cmd[1] + to_btm) / 2 - to_top;
	m = get_n_minmax_value(lst[A], cmd, to_move);
	m_btm = get_n_minmax_value(lst[A], cmd, to_btm);
	add_cmd_return(&lst[CMD], BR, to_btm);
	add_cmd_divide(&lst[CMD], B, to_btm);
	add_cmd_return(&lst[CMD], BR, to_move - to_btm);
	add_cmd_divide(&lst[CMD], B, to_move - to_btm);
	cmd[1] -= to_move;
	rr_back = divide_a_move_init(lst, to_move, m, m_btm);
	while (rr_back-- > 0)
		r_lst(lst, 'b');
	add_cmd_divide(&lst[CMD], A, ft_lstsize(lst[A]));
}

void	divide_a_init(t_list *lst[4], int to_btm, int to_top)
{
	int	*cmd;

	cmd = get_cmd(&lst[CMD]);
	if (cmd[1] > 3)
		divide_a_third_init(lst, cmd, to_btm, to_top);
	else
		sort_pair_a(lst, cmd[1], cmd[1]);
	del_int(cmd);
}
