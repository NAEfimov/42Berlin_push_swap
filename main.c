/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:52:21 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/19 22:16:43 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

// Sort linked list <lst_a>
// void	make_sort(void);

void	make_sort(int argc, char *argv[], t_list *lst[4], int len)
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
		ft_lstclear(&lst[A], del_int);
		ft_lstclear(&lst[OUT], del_int);
		len = read_args(argc, argv, &lst[A]);
		sort_lst(lst, len, to_btm);
		l_size = ft_lstsize(lst[OUT]);
		if (l_size < min)
			break ;
		to_btm++;
	}
}

int	main(int argc, char *argv[])
{
	int		len;
	t_list	*lst[4];

	lst[A] = NULL;
	lst[B] = NULL;
	lst[OUT] = NULL;
	len = read_args(argc, argv, &lst[A]);
	if (len < 0)
		return (print_error());
	else if (len == 0)
		return (0);
	else
		make_sort(argc, argv, lst, len);
	print_out(lst[OUT]);
	clear_list(lst);
	return (0);
}
