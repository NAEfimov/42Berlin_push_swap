/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:52:28 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/13 12:59:07 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

// Sort 3 first integers in the list (lowerst is first)
void	sort_triad_down(t_list **lst, char c)
{
	int	s;

	s = ft_lstsize(*lst);
	if (s == 2)
	{
		if (get_intn(*lst, 1) > get_intn(*lst, 2))
			s_lst(lst, c);
	}
	else if (s > 2)
	{
		while (!(lst_is_sorted_down(*lst, 3)))
		{
			if (get_intn(*lst, 1) > get_intn(*lst, 2))
				s_lst(lst, c);
			if (get_intn(*lst, 2) > get_intn(*lst, 3))
			{
				r_lst(lst, c);
				s_lst(lst, c);
				rr_lst(lst, c);
			}
		}
	}
}

// Sort 3 first integers in the list (highest is first)
void	sort_triad_up(t_list **lst, char c)
{
	int	s;

	s = ft_lstsize(*lst);
	if (s == 2)
	{
		if (get_intn(*lst, 1) < get_intn(*lst, 2))
			s_lst(lst, c);
	}
	else if (s > 2)
	{
		while (!(lst_is_sorted_up(*lst, 3)))
		{
			if (get_intn(*lst, 1) < get_intn(*lst, 2))
				s_lst(lst, c);
			if (get_intn(*lst, 2) < get_intn(*lst, 3))
			{
				r_lst(lst, c);
				s_lst(lst, c);
				rr_lst(lst, c);
			}
		}
	}
}

void	return_numbers(t_list **lst_a, t_list **lst_b, int *cmd)
{
	if (cmd[0] == AR)
		while (cmd[1]-- > 0)
			p_lst(lst_a, lst_b, 'b');
	else
		while (cmd[1]-- > 0)
			p_lst(lst_b, lst_a, 'a');
}

void	divide_lst_a(t_list **lst_a, t_list **lst_b, int *cmd, t_list **cmd_lst)
{
	int	m;
	int	to_move;
	int	r_count;
	int	rr_back;

	while (cmd[1] > 3)
	{
		to_move = cmd[1] / 2;
		m = get_mvalue(*lst_a, cmd);
		// printh_lst(*lst_a, 'a');				// PRINT
		// printh_lst(*lst_b, 'b');				// PRINT
		// printf("m: %i\n", m);					// PRINT
		// add_cmd_check(cmd_lst, BR, to_move);
		add_cmd(cmd_lst, BR, to_move);
		add_cmd(cmd_lst, B, to_move);
		// print_cmd(*cmd_lst);						// PRINT
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
			else
			{
				r_lst(lst_a, 'a');
				r_count++;
			}
		}
		while (rr_back && (r_count-- > 0))
			rr_lst(lst_a, 'a');
	}
	sort_triad_down(lst_a, 'a');
}

void	divide_lst_b(t_list **lst_a, t_list **lst_b, int *cmd, t_list **cmd_lst)
{
	int	m;
	int	to_move;
	int	r_count;

	while (cmd[1] > 3)
	{
		to_move = cmd[1] / 2;
		m = get_mvalue(*lst_b, cmd);
		// printh_lst(*lst_a, 'a');				// PRINT
		// printh_lst(*lst_b, 'b');				// PRINT
		// printf("m: %i\n", m);					// PRINT
		// add_cmd_check(cmd_lst, AR, to_move);
		add_cmd(cmd_lst, AR, to_move);
		add_cmd(cmd_lst, A, to_move);
		// print_cmd(*cmd_lst);						// PRINT
		r_count = 0;
		while (to_move > 0)
		{
			if (get_int(*lst_b) > m)
			{
				p_lst(lst_b, lst_a, 'a');
				to_move--;
				cmd[1]--;
			}
			else
			{
				r_lst(lst_b, 'b');
				r_count++;
			}
		}
		while (r_count-- > 0)
			rr_lst(lst_b, 'b');
	}
	sort_triad_up(lst_b, 'b');
	// printh_lst(*lst_a, 'a');				// PRINT
	// printh_lst(*lst_b, 'b');				// PRINT
}

void	make_sort(t_list **lst_a, t_list **lst_b, int len)
{
	t_list	*cmd_lst;
	int		*cmd;

	cmd_lst = NULL;
	init_cmd(&cmd_lst, len);
	
	// printh_lst(*lst_a, 'a');				// PRINT
	// printh_lst(*lst_b, 'b');				// PRINT
	// print_cmd(cmd_lst);						// PRINT
	
	while (cmd_lst)
	{
		cmd = get_cmd(&cmd_lst);
		// printf(" |%i %3i|\n",cmd[0], cmd[1]);					//PRINT
		if (cmd[0] == A)
		{
			divide_lst_a(lst_a, lst_b, cmd, &cmd_lst);
			// printh_lst(*lst_a, 'a');				// PRINT
			// printh_lst(*lst_b, 'b');				// PRINT
			// print_cmd(cmd_lst);						// PRINT
		}
		else if (cmd[0] == B)
		{
			divide_lst_b(lst_a, lst_b, cmd, &cmd_lst);
			// printh_lst(*lst_a, 'a');				// PRINT
			// printh_lst(*lst_b, 'b');				// PRINT
			// print_cmd(cmd_lst);						// PRINT
		}
		else
		{
			return_numbers(lst_a, lst_b, cmd);
			// printh_lst(*lst_a, 'a');				// PRINT
			// printh_lst(*lst_b, 'b');				// PRINT
			// print_cmd(cmd_lst);						// PRINT
		}
		del_int(cmd); // FREE COMMAND IN THE END OF IT
	}
	
	ft_lstclear(&cmd_lst, del_int);
}
