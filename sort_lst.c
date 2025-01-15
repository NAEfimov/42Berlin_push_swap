/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:52:28 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/15 13:13:49 by nefimov          ###   ########.fr       */
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

int		calc_opr_a(t_list *a, int len)
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
		if (get_int(b) > get_int(c) || (get_int(b) < get_int(c) && get_int(a) > get_int(c)))
			opr +=10;
		if (get_int(a) > get_int(c) && get_int(b) > get_int(c))
			opr +=100;
	}
	return (opr);
}

int		calc_opr_b(t_list *a, int len)
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
		if (get_int(b) < get_int(c) || (get_int(b) > get_int(c) && get_int(a) < get_int(c)))
			opr +=10;
		if (get_int(a) < get_int(c) && get_int(b) < get_int(c))
			opr +=100;
	}
	return (opr);
}

// For A
void	sort_pair_a(t_list **lst_a, t_list **lst_b, int len_a, int len_b)
{
	int	opr_a;
	int opr_b;

	if (ft_lstsize(*lst_a) < len_a)
		len_a = ft_lstsize(*lst_a);
	if (ft_lstsize(*lst_b) < len_b)
		len_b = ft_lstsize(*lst_b);
	opr_a = calc_opr_a(*lst_a, len_a);
	opr_b = calc_opr_b(*lst_b, len_b);
	// printh_lst(*lst_a, 'a');								//PRINT
	// printh_lst(*lst_b, 'b');								//PRINT
	// printf("opr_a: %i | opr_b: %i\n", opr_a, opr_b);	//PRINT
	if (opr_a % 10 == 1)
	{
		if (opr_b % 10 == 1)
			ss_lst(lst_a, lst_b);
		else
			s_lst(lst_a, 'a');
	}
	opr_a = opr_a / 10;
	opr_b = opr_b / 10;
	if (opr_a % 10 == 1)
	{
		if (opr_b % 10 == 1)
		{
			r_lst_ab(lst_a, lst_b);
			ss_lst(lst_a, lst_b);
			rr_lst_ab(lst_a, lst_b);
		}
		else
		{
			r_lst(lst_a, 'a');
			s_lst(lst_a, 'a');
			rr_lst(lst_a, 'a');
		}
	}
	opr_a = opr_a / 10;
	opr_b = opr_b / 10;	
	if (opr_a % 10 == 1)
	{
		if (opr_b % 10 == 1)
			ss_lst(lst_a, lst_b);
		else
			s_lst(lst_a, 'a');
	}
}

void	sort_pair_b(t_list **lst_a, t_list **lst_b, int len_a, int len_b)
{
	int	opr_a;
	int opr_b;

	if (ft_lstsize(*lst_a) < len_a)
		len_a = ft_lstsize(*lst_a);
	if (ft_lstsize(*lst_b) < len_b)
		len_b = ft_lstsize(*lst_b);
	opr_a = calc_opr_a(*lst_a, len_a);
	opr_b = calc_opr_b(*lst_b, len_b);
	// printh_lst(*lst_a, 'a');								//PRINT
	// printh_lst(*lst_b, 'b');								//PRINT
	// printf("opr_a: %i | opr_b: %i\n", opr_a, opr_b);	//PRINT
	if (opr_b % 10 == 1)
	{
		if (opr_a % 10 == 1)
			ss_lst(lst_a, lst_b);
		else
			s_lst(lst_b, 'b');
	}
	opr_a = opr_a / 10;
	opr_b = opr_b / 10;
	if (opr_b % 10 == 1)
	{
		if (opr_a % 10 == 1)
		{
			r_lst_ab(lst_a, lst_b);
			ss_lst(lst_a, lst_b);
			rr_lst_ab(lst_a, lst_b);
		}
		else
		{
			r_lst(lst_b, 'b');
			s_lst(lst_b, 'b');
			rr_lst(lst_b, 'b');
		}
	}
	opr_a = opr_a / 10;
	opr_b = opr_b / 10;	
	if (opr_b % 10 == 1)
	{
		if (opr_a % 10 == 1)
			ss_lst(lst_a, lst_b);
		else
			s_lst(lst_b, 'b');
	}
}

void	make_sort(t_list **lst_a, t_list **lst_b, int len)
{
	t_list	*cmd_lst;
	int		*cmd;

	cmd_lst = NULL;
	init_cmd(&cmd_lst, len);
	
		// printh_lst(*lst_a, 'a');				// PRINT
		// printh_lst(*lst_b, 'b');				// PRINT
		// print_cmd(cmd_lst);
		
	// cmd = get_cmd(&cmd_lst);
	// divide_lst_a_init(lst_a, lst_b, cmd, &cmd_lst);
	// del_int(cmd);
	
		// print_cmd(cmd_lst);
		// printh_lst(*lst_a, 'a');				// PRINT
		// printh_lst(*lst_b, 'b');				// PRINT
		
	while (cmd_lst)
	{
		cmd = get_cmd(&cmd_lst);
		if (cmd[0] == A)
			divide_lst_a(lst_a, lst_b, cmd, &cmd_lst);
		else if (cmd[0] == B)
			divide_lst_b(lst_a, lst_b, cmd, &cmd_lst);
		else
			return_numbers(lst_a, lst_b, cmd);
		del_int(cmd); // FREE COMMAND IN THE END OF IT
	}
	ft_lstclear(&cmd_lst, del_int);
}
