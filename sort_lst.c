/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:52:28 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/10 15:53:40 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

// Sort 3 first integers in the list (lowerst is first)
void	sort_triad_down(t_list **lst, char c)
{
	int	s;
	
	s = ft_lstsize(*lst);
	if (s == 2)
	{
		if (get_intn(*lst, 1) > get_intn(*lst, 2))
			s_lst(lst, c);
	}
	else if (s > 2)
	{
		while (!(lst_is_sorted_down(*lst, 3)))
		{
			if (get_intn(*lst, 1) > get_intn(*lst, 2))
				s_lst(lst, c);
			if (get_intn(*lst, 2) > get_intn(*lst, 3))
			{
				r_lst(lst, c);
				s_lst(lst, c);
				rr_lst(lst, c);
			}
		}
	}
}

// Sort 3 first integers in the list (highest is first)
void	sort_triad_up(t_list **lst, char c)
{
	int	s;
	
	s = ft_lstsize(*lst);
	if (s == 2)
	{
		if (get_intn(*lst, 1) < get_intn(*lst, 2))
			s_lst(lst, c);
	}
	else if (s > 2)
	{
		while (!(lst_is_sorted_up(*lst, 3)))
		{
			if (get_intn(*lst, 1) < get_intn(*lst, 2))
				s_lst(lst, c);
			if (get_intn(*lst, 2) < get_intn(*lst, 3))
			{
				r_lst(lst, c);
				s_lst(lst, c);
				rr_lst(lst, c);
			}
		}
	}
}
