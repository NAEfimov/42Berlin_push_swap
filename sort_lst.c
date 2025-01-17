/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:52:28 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/17 18:13:25 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

/* // Sort 3 first integers in the list (lowerst is first)
void	sort_triad_down(t_list **lst, char c)
{
	int	s;

	s = ft_lstsize(*lst);
	if (s == 2)
	{
		if (get_intn(*lst, 1) > get_intn(*lst, 2))
			s_lst(st,;
	}
	else if (s > 2)
	{
		while (!(lst_is_sorted_down(*lst, 3)))
		{
			if (get_intn(*lst, 1) > get_intn(*lst, 2))
				s_lst(st,;
			if (get_intn(*lst, 2) > get_intn(*lst, 3))
			{
				r_lst(lst, c);
				s_lst(st,;
				rr_lst(st,;
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
			s_lst(st,;
	}
	else if (s > 2)
	{
		while (!(lst_is_sorted_up(*lst, 3)))
		{
			if (get_intn(*lst, 1) < get_intn(*lst, 2))
				s_lst(st,;
			if (get_intn(*lst, 2) < get_intn(*lst, 3))
			{
				r_lst(lst, c);
				s_lst(st,;
				rr_lst(st,;
			}
		}
	}
} */

void	return_numbers(t_list *lst[4])
{
	int *cmd;

	cmd = get_cmd(&lst[CMD]);
	// printf("cmd: %i, %i\n", cmd[0], cmd[1]);
	if (cmd[0] == AR)
		while (cmd[1]-- > 0)
			p_lst(lst, 'b');
	else
		while (cmd[1]-- > 0)
			p_lst(lst, 'a');
	del_int(cmd);
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
void	sort_pair_a(t_list *lst[4], int len_a, int len_b)
{
	int	opr_a;
	int opr_b;

	if (ft_lstsize(lst[A]) < len_a)
		len_a = ft_lstsize(lst[A]);
	if (ft_lstsize(lst[B]) < len_b)
		len_b = ft_lstsize(lst[B]);
	opr_a = calc_opr_a(lst[A], len_a);
	opr_b = calc_opr_b(lst[B], len_b);
	// printh_lst(*lst_a, 'a');								//PRINT
	// printh_lst(*lst_b, 'b');								//PRINT
	// printf("opr_a: %i | opr_b: %i\n", opr_a, opr_b);	//PRINT
	if (opr_a % 10 == 1)
	{
		if (opr_b % 10 == 1)
			ss_lst(lst);
		else
			s_lst(lst, 'a');
	}
	opr_a = opr_a / 10;
	opr_b = opr_b / 10;
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
			r_lst(lst, 'a');
			s_lst(lst, 'a');
			rr_lst(lst, 'a');
		}
	}
	opr_a = opr_a / 10;
	opr_b = opr_b / 10;	
	if (opr_a % 10 == 1)
	{
		if (opr_b % 10 == 1)
			ss_lst(lst);
		else
			s_lst(lst, 'a');
	}
}

void	sort_pair_b(t_list *lst[4], int len_a, int len_b)
{
	int	opr_a;
	int opr_b;

	if (ft_lstsize(lst[A]) < len_a)
		len_a = ft_lstsize(lst[A]);
	if (ft_lstsize(lst[B]) < len_b)
		len_b = ft_lstsize(lst[B]);
	opr_a = calc_opr_a(lst[A], len_a);
	opr_b = calc_opr_b(lst[B], len_b);
	// printh_lst(*lst_a, 'a');								//PRINT
	// printh_lst(*lst_b, 'b');								//PRINT
	// printf("opr_a: %i | opr_b: %i\n", opr_a, opr_b);	//PRINT
	if (opr_b % 10 == 1)
	{
		if (opr_a % 10 == 1)
			ss_lst(lst);
		else
			s_lst(lst, 'b');
	}
	opr_a = opr_a / 10;
	opr_b = opr_b / 10;
	if (opr_b % 10 == 1)
	{
		if (opr_a % 10 == 1)
		{
			r_lst_ab(lst);
			ss_lst(lst);
			rr_lst_ab(lst);
		}
		else
		{
			r_lst(lst, 'b');
			s_lst(lst, 'b');
			rr_lst(lst, 'b');
		}
	}
	opr_a = opr_a / 10;
	opr_b = opr_b / 10;	
	if (opr_b % 10 == 1)
	{
		if (opr_a % 10 == 1)
			ss_lst(lst);
		else
			s_lst(lst, 'b');
	}
}

void	make_sort(t_list *lst[4], int len, int to_btm)
{
	int		*cmd;

	lst[CMD] = NULL;
	init_cmd(&lst[CMD], len);
	divide_lst_a_init(lst, to_btm);
	while (lst[CMD])
	{
		// printh_lst(lst[A], 'a');				// PRINT
		// printh_lst(lst[B], 'b');				// PRINT
		// print_cmd(lst[CMD]);
		cmd = read_cmd(lst[CMD]);
		if (cmd[0] == A)
			divide_lst_a(lst);
		else if (cmd[0] == B)
			divide_lst_b(lst);
		else
			return_numbers(lst);
		//del_int(cmd); // FREE COMMAND IN THE END OF IT
	}
	ft_lstclear(&lst[CMD], del_int);
}
