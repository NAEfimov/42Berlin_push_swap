/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:46:11 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/20 17:04:24 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

// Get the int value of the first lists node
int	get_int(t_list *lst)
{
	return (*(int *)lst->content);
}

// Get the int value of the n-th lists node
int	get_nint(t_list *lst, unsigned int n)
{
	while (n-- > 1)
		lst = lst->next;
	return (get_int(lst));
}

// Init list with NULL pointers
void	init_list(t_list *lst[LS])
{
	int	i;

	i = -1;
	while (++i < LS)
		lst[i] = NULL;
}

// Clear all the lists and exit the programm with <exit_code>
void	clear_exit(t_list *lst[LS], int exit_code)
{
	int	i;

	i = -1;
	while (++i < LS)
		ft_lstclear(&lst[i], free);
	exit(exit_code);
}

// Add an operator string to the OUT list
void	add_opr_out(t_list *lst[LS], char *str)
{
	t_list	*node;

	str = ft_strdup((const char *)str);
	if (str == NULL)
		clear_exit(lst, -2);
	node = ft_lstnew((void *)str);
	if (node == NULL)
	{
		free(str);
		clear_exit(lst, -2);
	}
	ft_lstadd_back(&lst[OUT], node);
}
