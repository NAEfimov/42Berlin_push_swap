/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:52:21 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/08 15:37:59 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

int	main(int argc, char *argv[])
{
	int		len_a;
	t_list	*lst_a;

	lst_a = NULL;
	len_a = read_args(argc, argv, &lst_a);
	if (len_a < 0)
		return (print_error());
	else if (len_a == 0)
		return (0);
	// else
	// 	make_sort();
	printh_lst(lst_a, 'a');
	ft_lstclear(&lst_a, del_int);
	return (0);
}
