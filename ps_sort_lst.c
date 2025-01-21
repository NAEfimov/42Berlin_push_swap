/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:52:28 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/21 19:22:39 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

// Get a command from a command list and return elements
void	return_elements(t_list *lst[LS])
{
	int	*cmd;

	cmd = get_cmd(&lst[CMD]);
	if (cmd[0] == AR)
		while (cmd[1]-- > 0)
			p_lst(lst, 'b');
	else
		while (cmd[1]-- > 0)
			p_lst(lst, 'a');
	free(cmd);
}

// Sort stack A
void	sort_lst(t_list *lst[LS], int len, int to_btm)
{
	int	*cmd;

	lst[CMD] = NULL;
	add_cmd_divide(lst, A, len);
	divide_init_a(lst, to_btm, len / 10 + 1);
	while (lst[CMD])
	{
		cmd = read_cmd(lst[CMD]);
		if (cmd[0] == A)
			divide_a(lst);
		else if (cmd[0] == B)
			divide_b(lst);
		else
			return_elements(lst);
	}
	ft_lstclear(&lst[CMD], free);
}

// Find optimal division proportion in intialization
// Make sort 
void	make_sort(int argc, char *argv[], t_list *lst[LS], int len)
{
	int		to_btm;
	int		min;
	int		l_size;

	to_btm = len / 4 - (len / 4) % 2;
	if (len <= 100)
		min = 700;
	else if (len <= 500)
		min = 5500;
	else
		min = INT_MAX;
	while (to_btm <= len / 2 - len / 10)
	{
		ft_lstclear(&lst[A], free);
		ft_lstclear(&lst[OUT], free);
		len = read_args(argc, argv, &lst[A]);
		sort_lst(lst, len, to_btm);
		l_size = ft_lstsize(lst[OUT]);
		if (l_size < min)
			break ;
		to_btm++;
	}
}
