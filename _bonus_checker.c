/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:46:03 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/21 14:55:40 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_bonus.h"

int	main(int argc, char *argv[])
{
	t_list	*lst[LS];
	int		len;
	char	**opr;

	init_list(lst);
	len = read_args(argc, argv, lst);
	if (len < 0)
		clean_lst_exit(lst, print_error("Error\n"));
	opr = read_stdio();
	if (opr == NULL)
		clean_lst_exit(lst, print_error("Error\n"));
	if (len > 0)
	{
		make_operations(lst, opr);
		if (ft_lstsize(lst[A]) == len && !lst[B]
			&& lst_is_sorted_down(lst[A], len))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	clean_opr(opr);
	clean_lst_exit(lst, 0);
}
