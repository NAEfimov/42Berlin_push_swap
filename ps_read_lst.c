/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_read_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:31:16 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/22 13:22:48 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

// Convert string <str> to integer number <int>,
// allocate memory for it and return a pointer for the number.
// If there is a reading error return <NULL>
int	*read_num(char *str)
{
	long int	num;
	int			sign;
	int			*read;
	int			is_num;

	sign = 1;
	num = 0;
	is_num = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str++ - '0');
		is_num = 1;
	}
	num = sign * num;
	if (is_num == 0 || *str != '\0' || num < INT_MIN || num > INT_MAX)
		return (NULL);
	read = malloc(sizeof(int));
	if (read != NULL)
		*read = (int) num;
	return (read);
}

// Function to check for int <num> duplicates in list <lst>
void	check_dup(int **num, t_list *lst)
{
	while (*num && lst != NULL)
	{
		if (**num == get_int(lst))
		{
			free(*num);
			*num = NULL;
		}
		lst = lst->next;
	}
}

// Check for correct input and read it to a list of integers
// Get <argc> and <argv> from main function as input and <*lst_a> as output list
// Return: <-1> if error; <0> if no args; length of <lst_a> if read is OK
int	read_args(int argc, char *argv[], t_list *lst[LS])
{
	int		i;
	int		*num;
	t_list	*new_node;

	i = 0;
	if (argc == 1)
		return (0);
	else
	{
		i = 1;
		while (i < argc)
		{
			num = read_num(argv[i]);
			check_dup(&num, lst[A]);
			if (num == NULL)
				return (-1);
			new_node = ft_lstnew(num);
			if (new_node == NULL)
				clean_lst_exit(lst, -2);
			ft_lstadd_back(&lst[A], new_node);
			i++;
		}
	}
	return (i - 1);
}
