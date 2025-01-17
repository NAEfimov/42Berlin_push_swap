/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:52:21 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/17 15:12:50 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

// Sort linked list <lst_a>
// void	make_sort(void);

int	main(int argc, char *argv[])
{
	int		len;
	t_list	*lst[2];
	// t_list	*lst_a;
	// t_list	*lst_b;

	// lst_a = NULL;
	// lst_b = NULL;
	lst[A] = NULL;
	lst[B] = NULL;
	len = read_args(argc, argv, lst);
	if (len < 0)
		return (print_error());
	else if (len == 0)
		return (0);
	else
		make_sort(lst, len);
	// printh_lst(lst_a, 'a');					//PRINT
	// printh_lst(lst_b, 'b');					//PRINT
	ft_lstclear(&lst[A], del_int);
	ft_lstclear(&lst[B], del_int);
	return (0);
}
