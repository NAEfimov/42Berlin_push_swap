/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:46:33 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/17 17:12:39 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

void	divide_lst_a(t_list *lst[3])
{
	int	m;
	int	to_move;
	int	r_count;
	int	rr_back;
	int *cmd;

	cmd = get_cmd(&lst[CMD]);
	// printf("cmd: %i, %i\n", cmd[0], cmd[1]);
	while (cmd[1] > 3 && lst_is_sorted_down(lst[A], cmd[1]) == 0)
	{
		to_move = cmd[1] / 2;
		m = get_n_minmax_value(lst[A], cmd, to_move);
				// printh_lst(lst[A], 'a');				// PRINT
				// printh_lst(lst[B], 'b');				// PRINT
				// printf("m: %i\n", m);					// PRINT
		add_cmd_check(&lst[CMD], BR, to_move);
		add_cmd(&lst[CMD], B, to_move);
		rr_back = 1;
		if (cmd[1] == ft_lstsize(lst[A]))
			rr_back = 0;
		r_count = 0;
		while (to_move > 0)
		{
			if (get_int(lst[A]) < m)
			{
				p_lst(&lst[A], &lst[B], 'b');
				to_move--;
				cmd[1]--;
			}
			else if ((to_move == 1) && lst[A]->next && get_int((lst[A])->next) < m)
				s_lst_pair(&lst[A], &lst[B]);
			else
			{
				r_lst(&lst[A], 'a');
				if (rr_back)
					r_count++;
			}
		}
		while (r_count-- > 0)
			rr_lst(&lst[A], 'a');
	}
		// printh_lst(*lst_a, 'a');				// PRINT
		// printh_lst(*lst_b, 'b');				// PRINT
	
	sort_pair_a(lst, cmd[1], cmd[1]);
	
		// printh_lst(*lst_a, 'a');				// PRINT
		// printh_lst(*lst_b, 'b');				// PRINT
	del_int(cmd);
}

void	divide_lst_b(t_list *lst[3])
{
	int	m;
	int	to_move;
	int	r_count;
	int	rr_back;
	int *cmd;

	cmd = get_cmd(&lst[CMD]);
	// printf("cmd: %i, %i\n", cmd[0], cmd[1]);
	while (cmd[1] > 3 && lst_is_sorted_up(lst[B], cmd[1]) == 0)
	{
		to_move = cmd[1] / 2;
		m = get_n_minmax_value(lst[B], cmd, to_move);
				// printh_lst(lst[A], 'a');				// PRINT
				// printh_lst(lst[B], 'b');				// PRINT
				// printf("m: %i\n", m);					// PRINT
		add_cmd_check(&lst[CMD], AR, to_move);
		add_cmd(&lst[CMD], A, to_move);
		rr_back = 1;
		if (cmd[1] == ft_lstsize(lst[B]))
			rr_back = 0;
		r_count = 0;
		while (to_move > 0)
		{
			if (get_int(lst[B]) > m)
			{
				p_lst(&lst[B], &lst[A], 'a');
				to_move--;
				cmd[1]--;
			}
			else if ((to_move == 1) && lst[B]->next && get_int((lst[B])->next) > m)
				s_lst_pair(&lst[A], &lst[B]);
			else
			{
				r_lst(&lst[B], 'b');
				r_count++;
			}
		}
		while (rr_back && (r_count-- > 0))
			rr_lst(&lst[B], 'b');
	}
	
		// printh_lst(*lst_a, 'a');				// PRINT
		// printh_lst(*lst_b, 'b');				// PRINT
	
	sort_pair_b(lst, cmd[1], cmd[1]);

		// printh_lst(*lst_a, 'a');				// PRINT
		// printh_lst(*lst_b, 'b');				// PRINT
	
	del_int(cmd);
}
int	ft_sqrt(int num)
{
	int i;

	i = 0;
	while (num > i * i)
		i++;
	return (i);	
}

void	divide_lst_a_init(t_list *lst[3], int to_btm)
{
	int	m;
	int	m_btm;
	int	to_move;
	int	r_count;
	int	rr_back;
	int	*cmd;

	cmd = get_cmd(&lst[CMD]);
	if (cmd[1] > 3)
	{
		to_move = (cmd[1] + to_btm) / 2;
				// printf("to_fr: %i| to_move: %i\n", to_fr, to_move);				// PRINT
		m = get_n_minmax_value(lst[A], cmd, (cmd[1] + to_btm) / 2);
		m_btm = get_n_minmax_value(lst[A], cmd, to_btm);
				// printh_lst(*lst_a, 'a');				// PRINT
				// printh_lst(*lst_b, 'b');				// PRINT
				// printf("m: %i| m_fr: %i\n", m, m_fr);				// PRINT
				
		// add_cmd_check(cmd_lst, BR, to_move);
		// add_cmd(cmd_lst, B, to_move - to_fr);

		add_cmd_check(&lst[CMD], BR, to_btm);
		add_cmd(&lst[CMD], B, to_btm);
		add_cmd_check(&lst[CMD], BR, to_move - to_btm);
		add_cmd(&lst[CMD], B, to_move - to_btm);
		
		r_count = 0;
		rr_back = 0;
		while (to_move > 0)
		{
			if (get_int(lst[A]) < m)
			{
				if (get_int(lst[A]) < m_btm)
				{
					p_lst(&lst[A], &lst[B], 'b');
					if ((lst[B])->next)
						rr_back++;
					to_move--;
					cmd[1]--;
					// printh_lst(*lst_a, 'a');				// PRINT
					// printh_lst(*lst_b, 'b');				// PRINT
					// printf("rr_back: %i\n", rr_back);				// PRINT
				}
				else
				{
					while (rr_back > 0)
					{						
						r_lst(&lst[B], 'b');
						rr_back--;
					}
					p_lst(&lst[A], &lst[B], 'b');
					to_move--;
					cmd[1]--;
					// printh_lst(*lst_a, 'a');				// PRINT
					// printh_lst(*lst_b, 'b');				// PRINT
					// printf("rr_back: %i\n", rr_back);				// PRINT
				}
			}
			else
			{
				if (rr_back > 0)
				{
					r_lst_ab(lst);
					rr_back--;
				}
				else
					r_lst(&lst[A], 'a');
			}
			
		}
		while (rr_back-- > 0)					
			r_lst(&lst[B], 'b');
		while (r_count-- > 0)
			rr_lst(&lst[A], 'a');
		add_cmd(&lst[CMD], A, ft_lstsize(lst[A]));
			
		// printh_lst(*lst_a, 'a');				// PRINT
		// printh_lst(*lst_b, 'b');				// PRINT

		
	
	}
	else
	{
			// printh_lst(*lst_a, 'a');				// PRINT
			// printh_lst(*lst_b, 'b');				// PRINT
	
		sort_pair_a(lst, cmd[1], cmd[1]);
	
			// printh_lst(*lst_a, 'a');				// PRINT
			// printh_lst(*lst_b, 'b');				// PRINT
	}
	del_int(cmd);
}
