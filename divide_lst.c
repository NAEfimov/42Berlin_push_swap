/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:46:33 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/14 18:57:30 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

void	divide_lst_a_pair(t_list **lst_a, t_list **lst_b, int *cmd, t_list **cmd_lst)
{
	int	m;
	int	to_move;
	int	r_count;
	int	rr_back;

	while (cmd[1] > 3)
	{
		to_move = cmd[1] / 2;
		m = get_median_value(*lst_a, cmd);
		// printh_lst(*lst_a, 'a');				// PRINT
		// printh_lst(*lst_b, 'b');				// PRINT
		// printf("m: %i\n", m);					// PRINT
		add_cmd_check(cmd_lst, BR, to_move);
		add_cmd(cmd_lst, B, to_move);
		rr_back = 1;
		if (cmd[1] == ft_lstsize(*lst_a))
			rr_back = 0;
		r_count = 0;
		while (to_move > 0)
		{
			if (get_int(*lst_a) < m)
			{
				// if ((to_move == 3) && (get_int((*lst_a)->next) < get_int(*lst_a)))
				// 	s_lst_pair(lst_a, lst_b);
				p_lst(lst_a, lst_b, 'b');
				to_move--;
				cmd[1]--;
			}
			else if ((to_move == 1) && (*lst_a)->next && get_int((*lst_a)->next) < m)
				s_lst_pair(lst_a, lst_b);
			else
			{
				r_lst(lst_a, 'a');
				if (rr_back)
					r_count++;
			}
		}
		while (r_count-- > 0)
			rr_lst(lst_a, 'a');
	}
		// printh_lst(*lst_a, 'a');				// PRINT
		// printh_lst(*lst_b, 'b');				// PRINT
	
	sort_pair_a(lst_a, lst_b, cmd[1], cmd[1]);
	// sort_triad_down(lst_a, 'a');
	
		// printh_lst(*lst_a, 'a');				// PRINT
		// printh_lst(*lst_b, 'b');				// PRINT
}

void	divide_lst_b_pair(t_list **lst_a, t_list **lst_b, int *cmd, t_list **cmd_lst)
{
	int	m;
	int	to_move;
	int	r_count;
	int	rr_back;
	// int	*cmd_n;

	while (cmd[1] > 3)
	{
		to_move = cmd[1] / 2;
		m = get_median_value(*lst_b, cmd);
		add_cmd_check(cmd_lst, AR, to_move);
		add_cmd(cmd_lst, A, to_move);
		rr_back = 1;
		if (cmd[1] == ft_lstsize(*lst_b))
			rr_back = 0;
		r_count = 0;
		while (to_move > 0)
		{
			if (get_int(*lst_b) > m)
			{
				// if ((to_move == 3) && (get_int((*lst_b)->next) < get_int(*lst_b)))
				// 	s_lst_pair(lst_a, lst_b);
				p_lst(lst_b, lst_a, 'a');
				to_move--;
				cmd[1]--;
			}
			else if ((to_move == 1) && (*lst_b)->next && get_int((*lst_b)->next) > m)
				s_lst_pair(lst_a, lst_b);
			else
			{
				r_lst(lst_b, 'b');
				r_count++;
			}
		}
		while (rr_back && (r_count-- > 0))
			rr_lst(lst_b, 'b');
	}
	
		// printh_lst(*lst_a, 'a');				// PRINT
		// printh_lst(*lst_b, 'b');				// PRINT
	
	sort_pair_b(lst_a, lst_b, cmd[1], cmd[1]);
	// sort_triad_up(lst_b, 'b');

		// printh_lst(*lst_a, 'a');				// PRINT
		// printh_lst(*lst_b, 'b');				// PRINT
	
}
