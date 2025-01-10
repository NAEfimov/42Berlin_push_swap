/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:37:08 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/10 16:06:59 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

// Print a string <*err> on the standard error and return <0>
int	print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

//Print list vertical
void	printv_lst(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%i\n", *(int *)lst->content);
		lst = lst->next;
	}
}

//Print list vertical
void	printh_lst(t_list *lst, char c)
{
	printf("%c| ", c);
	while (lst != NULL)
	{
		printf("%3i ", *(int *)lst->content);
		lst = lst->next;
	}
	printf("\n");
}
