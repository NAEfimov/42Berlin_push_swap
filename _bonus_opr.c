/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus_opr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:44:03 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/21 15:19:11 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_bonus.h"

// Clean operations array memory
void	clean_opr(char **opr)
{
	int	i;	

	if (opr)
	{
		i = 0;
		while (opr[i])
		{
			free(opr[i]);
			i++;
		}
		free(opr);
	}
}

// Check operator for syntax and apply it to the stacks
int	check_operation(t_list *lst[LS], char *opr)
{
	if (!ft_strcmp(opr, "sa") || !ft_strcmp(opr, "sb"))
		s_lst(lst, opr[1]);
	else if (!ft_strcmp(opr, "ss"))
		ss_lst(lst);
	else if (!ft_strcmp(opr, "pa") || !ft_strcmp(opr, "pb"))
		p_lst(lst, opr[1]);
	else if (!ft_strcmp(opr, "ra") || !ft_strcmp(opr, "rb"))
		r_lst(lst, opr[1]);
	else if (!ft_strcmp(opr, "rr"))
		r_lst_ab(lst);
	else if (!ft_strcmp(opr, "rra") || !ft_strcmp(opr, "rrb"))
		rr_lst(lst, opr[2]);
	else if (!ft_strcmp(opr, "rrr"))
		rr_lst_ab(lst);
	else
		return (1);
	return (0);
}

// Take next operator from the array and apply it to the stacks
// If operator is wrong - clean memoty and exit the program
void	make_operations(t_list *lst[LS], char **opr)
{
	int	i;

	i = 0;
	while (opr[i])
	{
		if (check_operation(lst, opr[i]) == 1)
		{
			clean_opr(opr);
			clean_lst_exit(lst, print_error("Error\n"));
		}
		i++;
	}
}
