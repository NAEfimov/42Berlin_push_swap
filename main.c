/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:52:21 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/21 15:01:20 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

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
