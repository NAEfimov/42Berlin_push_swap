/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:52:21 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/17 19:26:03 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

// Sort linked list <lst_a>
// void	make_sort(void);

int	main(int argc, char *argv[])
{
	int		len;
	t_list	*lst[4];
	int		del;
	int		del_m;
	int		min;
	int		l_size;

	lst[A] = NULL;
	lst[B] = NULL;
	lst[OUT] = NULL;
	len = read_args(argc, argv, &lst[A]);
	if (len < 0)
		return (print_error());
	else if (len == 0)
		return (0);
	else
	{
		del = len / 10;
		min = INT_MAX;
		while (del < len / 2)
		{
			ft_lstclear(&lst[A], del_int);
			len = read_args(argc, argv, &lst[A]);
			make_sort(lst, len, del);
			l_size = ft_lstsize(lst[OUT]);
			if (l_size < min)
			{
				min = l_size;
				del_m = del;
			}
			ft_lstclear(&lst[OUT], del_int);
			del++;
		}
		ft_lstclear(&lst[A], del_int);
		len = read_args(argc, argv, &lst[A]);
		make_sort(lst, len, del_m);
	}	
	// printh_lst(lst[A], 'a');					//PRINT
	// printh_lst(lst[B], 'b');					//PRINT
	print_out(lst[OUT]);
	
	ft_lstclear(&lst[A], del_int);
	ft_lstclear(&lst[B], del_int);
	ft_lstclear(&lst[CMD], del_int);
	ft_lstclear(&lst[OUT], del_int);
	return (0);
}
