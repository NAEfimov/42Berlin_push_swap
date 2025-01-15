/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:46:33 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/15 13:13:19 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

void	divide_lst_a(t_list **lst_a, t_list **lst_b, int *cmd, t_list **cmd_lst)
{
	int	m;
	int	to_move;
	int	r_count;
	int	rr_back;

	while (cmd[1] > 3)
	{
		to_move = cmd[1] / 2;
		m = get_n_minmax_value(*lst_a, cmd, to_move);
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
	
		// printh_lst(*lst_a, 'a');				// PRINT
		// printh_lst(*lst_b, 'b');				// PRINT
}

void	divide_lst_b(t_list **lst_a, t_list **lst_b, int *cmd, t_list **cmd_lst)
{
	int	m;
	int	to_move;
	int	r_count;
	int	rr_back;

	while (cmd[1] > 3)
	{
		to_move = cmd[1] / 2;
		m = get_n_minmax_value(*lst_b, cmd, to_move);
				// printh_lst(*lst_a, 'a');				// PRINT
				// printh_lst(*lst_b, 'b');				// PRINT
				// printf("m: %i\n", m);					// PRINT
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

		// printh_lst(*lst_a, 'a');				// PRINT
		// printh_lst(*lst_b, 'b');				// PRINT
	
}
int	ft_sqrt(int num)
{
	int i;

	i = 0;
	while (num > i * i)
		i++;
	return (i);	
}

void	divide_lst_a_init(t_list **lst_a, t_list **lst_b, int *cmd, t_list **cmd_lst)
{
	int	m;
	int	m_fr;
	int	to_move;
	int to_fr;
	int	r_count;
	int	rr_back;

	if (cmd[1] > 3)
	{
		to_fr = ft_sqrt(cmd[1]) / 2;
		to_move = (cmd[1] + to_fr) / 2;
				// printf("to_fr: %i| to_move: %i\n", to_fr, to_move);				// PRINT
		m = get_n_minmax_value(*lst_a, cmd, (cmd[1] + to_fr) / 2);
		m_fr = get_n_minmax_value(*lst_a, cmd, to_fr);
				// printh_lst(*lst_a, 'a');				// PRINT
				// printh_lst(*lst_b, 'b');				// PRINT
				// printf("m: %i| m_fr: %i\n", m, m_fr);				// PRINT
		add_cmd_check(cmd_lst, BR, to_move);
		add_cmd(cmd_lst, B, to_move - to_fr);
		
		r_count = 0;
		rr_back = 0;
		while (to_move > 0)
		{
			if (get_int(*lst_a) < m)
			{
				if (get_int(*lst_a) < m_fr)
				{
					while (rr_back > 0 && get_int(*lst_a) < get_int(*lst_b))
					{
						r_lst(lst_b, 'b');
						rr_back--;
					}
					while (*lst_b && (get_int(*lst_a) > get_int(ft_lstlast(*lst_b))))
						{
							rr_lst(lst_b, 'b');
							rr_back++;
						}
					p_lst(lst_a, lst_b, 'b');
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
						r_lst(lst_b, 'b');
						rr_back--;
					}
					p_lst(lst_a, lst_b, 'b');
					to_move--;
					cmd[1]--;
					// printh_lst(*lst_a, 'a');				// PRINT
					// printh_lst(*lst_b, 'b');				// PRINT
					// printf("rr_back: %i\n", rr_back);				// PRINT
				}
			}
			/* else if ((to_move == 1) && (*lst_a)->next && get_int((*lst_a)->next) < m)
				s_lst_pair(lst_a, lst_b); */
			else
			{
				if (rr_back > 0)
				{
					r_lst_ab(lst_a, lst_b);
					rr_back--;
				}
				else
					r_lst(lst_a, 'a');
			}
		}
		while (rr_back-- > 0)					
			r_lst(lst_b, 'b');
		while (r_count-- > 0)
			rr_lst(lst_a, 'a');
		add_cmd(cmd_lst, A, ft_lstsize(*lst_a));
			
		// printh_lst(*lst_a, 'a');				// PRINT
		// printh_lst(*lst_b, 'b');				// PRINT

		
	
	}
	else
	{
			// printh_lst(*lst_a, 'a');				// PRINT
			// printh_lst(*lst_b, 'b');				// PRINT
	
		sort_pair_a(lst_a, lst_b, cmd[1], cmd[1]);
	
			// printh_lst(*lst_a, 'a');				// PRINT
			// printh_lst(*lst_b, 'b');				// PRINT
	}
}
