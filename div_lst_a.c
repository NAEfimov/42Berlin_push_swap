/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_lst_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:46:33 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/20 15:45:13 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

// Move <to_move> elements from stack A to stack B 
int	divide_a_move(t_list *lst[LS], int to_move, int m)
{
	int	r_count;

	r_count = 0;
	while (to_move > 0)
	{
		if (get_int(lst[A]) < m)
		{
			p_lst(lst, 'b');
			to_move--;
		}
		else if ((to_move == 1) && lst[A]->next && get_int((lst[A])->next) < m)
			s_lst_pair(lst);
		else
		{
			r_lst(lst, 'a');
			r_count++;
		}
	}
	return (r_count);
}

// Divide stack A by half
void	divide_a_half(t_list *lst[LS], int *cmd)
{
	int	m;
	int	to_move;
	int	r_count;
	int	rr_back;

	to_move = cmd[1] / 2;
	m = get_n_minmax_value(lst[A], cmd, to_move);
	add_cmd_return(lst, BR, to_move);
	add_cmd_divide(lst, B, to_move);
	rr_back = 1;
	if (cmd[1] == ft_lstsize(lst[A]))
		rr_back = 0;
	cmd[1] -= to_move;
	r_count = divide_a_move(lst, to_move, m);
	while (rr_back && (r_count-- > 0))
		rr_lst(lst, 'a');
}

// Divide stack A by half if number of elements more than 3
// Else sort the elements 
void	divide_a(t_list *lst[LS])
{
	int	*cmd;

	cmd = get_cmd(&lst[CMD]);
	while (cmd[1] > 3)
		divide_a_half(lst, cmd);
	sort_pair_a(lst, cmd[1], cmd[1]);
	free(cmd);
}
