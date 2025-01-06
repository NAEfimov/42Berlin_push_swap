/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:52:21 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/06 15:36:35 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Check for correct input and read it to a list of integers
// Get <argc> and <argv> from main function as input and <*lst_a> as output list
// Return: <-1> if error; <0> if no args; length of <lst_a> if read is OK
int	read_input(void)
{
	return (0);
}

// Print a string <*err> on the standard error and return <0>
int	print_error(char *err)
{
	return (0);
}

// Sort linked list <lst_a>
void	make_sort(void);

int	main(int argc, char *argv[])
{
	int	len_a;

	len_a = read_input();
	if (len_a < 0)
		return (print_error("Error\n"));
	else if (len_a == 0)
		return (0);
	else
		make_sort();
	return (0);
}
