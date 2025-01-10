/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:52:21 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/10 15:57:44 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

// Sort linked list <lst_a>
// void	make_sort(void);

int	main(int argc, char *argv[])
{
	int		len;
	t_list	*lst_a;

	lst_a = NULL;
	len = read_args(argc, argv, &lst_a);
	if (len < 0)
		return (print_error());
	else if (len == 0)
		return (0);
	// else
	// 	make_sort();
	printh_lst(lst_a, 'a');
	// sort_triad_up(&lst_a, 'a');
	// printh_lst(lst_a, 'a');
	ft_lstclear(&lst_a, del_int);
	return (0);
}
