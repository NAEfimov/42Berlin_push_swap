/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:52:21 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/06 18:48:04 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

// Check for correct input and read it to a list of integers
// Get <argc> and <argv> from main function as input and <*lst_a> as output list
// Return: <-1> if error; <0> if no args; length of <lst_a> if read is OK
int	read_input(int argc, char *argv[], t_list **lst_a)
{
	int		i;
	t_list	*new_node;

	i = 0;
	if (argc == 1)
		return(0);
	else
	{ 
		i = 1;
		while (i < argc)
		{
			new_node = ft_lstnew(argv[i]);
			ft_lstadd_back(lst_a, new_node);
			i++;
		}
	}
	return (i);
}

// Print a string <*err> on the standard error and return <0>
int	print_error()
{
	write(3, "Error\n", 6);
	write(1, "Error\n", 6);
	return (0);
}

// Sort linked list <lst_a>
// void	make_sort(void);

//Print list
void print_lst(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}

int	main(int argc, char *argv[])
{
	int		len_a;
	t_list	*lst_a;

	lst_a = NULL;
	len_a = read_input(argc, argv, &lst_a);
	if (len_a < 0)
		return (print_error());
	else if (len_a == 0)
		return (0);
	// else
	// 	make_sort();
	print_lst(lst_a);
	return (0);
}
