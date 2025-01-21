/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:52:21 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/21 14:37:09 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

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

// Initialise list, read input and sort stack A if valid input
int	main(int argc, char *argv[])
{
	int		len;
	t_list	*lst[4];

	init_list(lst);
	len = read_args(argc, argv, lst);
	if (len < 0)
		print_error("Error\n");
	else if (len == 0)
		clean_lst_exit(lst, 0);
	else
		make_sort(argc, argv, lst, len);
	print_out(lst[OUT]);
	clean_lst_exit(lst, 0);
}
