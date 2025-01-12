/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:52:28 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/12 14:05:16 by nefimov          ###   ########.fr       */
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

void make_sort(t_list **lst_a, t_list **lst_b, int len)
{
	t_list	*cmd_lst;
	int		*cmd;

	cmd_lst = NULL;
	init_cmd(&cmd_lst, len);
	
	printh_lst(*lst_a, 'a');
	printh_lst(*lst_b, 'b');
	print_cmd(cmd_lst);
	
	add_cmd(&cmd_lst, B, 4);
	print_cmd(cmd_lst);
	
	cmd = read_cmd(cmd_lst);
	printf(" |%i %2i|\n",cmd[0], cmd[1]);
	print_cmd(cmd_lst);
	
	cmd = get_cmd(&cmd_lst);
	printf(" |%i %2i|\n",cmd[0], cmd[1]);
	print_cmd(cmd_lst);
	del_int(cmd); // FREE COMMAND IN THE END OF IT

	cmd = get_cmd(&cmd_lst);
	printf(" |%i %2i|\n",cmd[0], cmd[1]);
	print_cmd(cmd_lst);
	del_int(cmd); // FREE COMMAND IN THE END OF IT

	ft_lstclear(&cmd_lst, del_int);
}
