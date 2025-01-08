/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:52:21 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/08 18:03:44 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

// Sort linked list <lst_a>
// void	make_sort(void);

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

void	r_lst(t_list **lst, char c)
{
	t_list	*first;
	t_list	*second;

	first = *lst;
	if (first->next)
	{
		second = first->next;
		ft_lstadd_back(lst, first);
		first->next = NULL;
		*lst = second;
	}
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	rr_lst(t_list **lst, char c)
{
	t_list	*last;
	t_list	*pre_last;

	pre_last = *lst;
	if (pre_last->next)
	{
		last = pre_last->next;
		while (last->next)
		{
			pre_last = last;
			last = pre_last->next;
		}
		pre_last->next = NULL;
		ft_lstadd_front(lst, last);
	}
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	s_lst(t_list **lst, char c)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!lst || !(*lst)->next)
		return ;
	first = *lst;
	second = (*lst)->next;
	third = second->next;
	second->next = first;
	first->next = third;
	*lst = second;
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

int	lst_is_sorted_down(t_list *lst, int n)
{
	t_list	*c_node;
	t_list	*n_node;
	
	if (!lst || !lst->next || n < 2)
		return (1);
	c_node = lst;
	n_node = c_node->next;
	while (n_node && (n >= 2))
	{
		// if (*(int *)(c_node->content) > *(int *)(n_node->content))
		if (get_int(c_node) > get_int(n_node))
			return (0);
		c_node = n_node;
		n_node = n_node->next;
		n--;
	}
	return (1);
}

int	lst_is_sorted_up(t_list *lst, int n)
{
	t_list	*c_node;
	t_list	*n_node;
	
	if (!lst || !lst->next || n < 2)
		return (1);
	c_node = lst;
	n_node = c_node->next;
	while (n_node && (n >= 2))
	{
		if (get_int(c_node) < get_int(n_node))
			return (0);
		c_node = n_node;
		n_node = n_node->next;
		n--;
	}
	return (1);
}

// Sort 3 first integers in the list
/* void	sort_triad_down(t_list **lst)
{
	int		num[3];
	int		i;
	t_list	*node;
	
	node = *lst;
	i = -1;
	while (++i < 3)
	{
		num[i] = get_int(node);
		node = node->next;
	}
	while (!(lst_is_sorted_down(*lst, 3)))
	{
		if ()
	}
} */

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
	if (lst_is_sorted_down(lst_a, len))
		ft_putstr_fd("Sorted down\n", 1);
	else
		ft_putstr_fd("NOT sorted down\n", 1);
	printf("Content [%i]: %i\n", len, get_intn(lst_a, len));
	ft_lstclear(&lst_a, del_int);
	return (0);
}
