/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:46:11 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/10 15:46:40 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

int	get_int(t_list *lst)
{
	return (*(int *)lst->content);
}

int	get_intn(t_list *lst, unsigned int n)
{
	while (n-- > 1)
		lst = lst->next;
	return (get_int(lst));
}
