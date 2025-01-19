/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_lst_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:16:30 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/19 21:17:00 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

int	divide_b_move(t_list *lst[4], int to_move, int m)
{
	int	r_count;

	r_count = 0;
	while (to_move > 0)
	{
		if (get_int(lst[B]) > m)
		{
			p_lst(lst, 'a');
			to_move--;
		}
		else if ((to_move == 1) && lst[B]->next && get_int((lst[B])->next) > m)
			s_lst_pair(lst);
		else
		{
			r_lst(lst, 'b');
			r_count++;
		}
	}
	return (r_count);
}

void	divide_b_half(t_list *lst[4], int *cmd)
{
	int	m;
	int	to_move;
	int	r_count;
	int	rr_back;

	to_move = cmd[1] / 2;
	m = get_n_minmax_value(lst[B], cmd, to_move);
	add_cmd_return(&lst[CMD], AR, to_move);
	add_cmd_divide(&lst[CMD], A, to_move);
	rr_back = 1;
	if (cmd[1] == ft_lstsize(lst[B]))
		rr_back = 0;
	cmd[1] -= to_move;
	r_count = divide_b_move(lst, to_move, m);
	while (rr_back && (r_count-- > 0))
		rr_lst(lst, 'b');
}

void	divide_b(t_list *lst[4])
{
	int	*cmd;

	cmd = get_cmd(&lst[CMD]);
	while (cmd[1] > 3)
		divide_b_half(lst, cmd);
	sort_pair_b(lst, cmd[1], cmd[1]);
	del_int(cmd);
}
