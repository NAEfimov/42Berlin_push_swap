/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:52:21 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/10 15:53:09 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

// Sort linked list <lst_a>
// void	make_sort(void);

void	init_m(t_list *lst, int size, int mm[4])
{
	int		i;
	int		num;

	i = -1;
	while (++i < size)
	{
		num = get_int(lst);
		if (num > mm[1])
			mm[0] = num;
		if (num < mm[3])
			mm[2] = num;
		lst = lst->next;		
	}
}

// Get median value of first <size> nodes in list <lst>
// mm[4](min_max[4]): <curr_min> <next min> <curr_max> <next_max> 
int	get_mvalue(t_list *lst, int size)
{
	t_list	*node;
	int		i;
	int		j;
	int		mm[4];

	mm[1] = INT_MIN;
	mm[3] = INT_MAX;
	i = -1;
	while (++i <= size / 2)
	{
		node = lst;
		j = -1;
		init_m(lst, size, mm);
		while (++j < size)
		{
			if (get_int(node) > mm[1] && get_int(node) < mm[0])
				mm[0] = get_int(node);
			if (get_int(node) < mm[3] && get_int(node) > mm[2])
				mm[2] = get_int(node);
			node = node->next;
		}
		mm[1] = mm[0];
		mm[3] = mm[2];
	}
	return (mm[0]);
}

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
