/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:37:08 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/21 12:03:26 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

// Print a string <*err> on the standard error and return <0>
int	print_error(char *err_msg)
{
	int	len;

	len = ft_strlen(err_msg);
	write(2, err_msg, len);
	return (1);
}

// Function to print list elements line by line
void	printv_lst(t_list *lst)
{
	char	*str;

	while (lst != NULL)
	{
		str = ft_itoa(get_int(lst));
		if (str)
		{
			ft_putstr_fd(str, 1);
			ft_putstr_fd("\n", 1);
			free(str);
		}
		lst = lst->next;
	}
}

// Function to print list elements in a line
void	printh_lst(t_list *lst, char c)
{
	char	*str;

	write(1, &c, 1);
	ft_putstr_fd("| ", 1);
	while (lst != NULL)
	{
		str = ft_itoa(get_int(lst));
		if (str)
		{
			ft_putstr_fd(str, 1);
			write(1, " ", 1);
			free(str);
		}
		lst = lst->next;
	}
	write(1, "\n", 1);
}

// Function to print commands list
void	print_cmd(t_list *lst)
{
	int		*cmd;
	char	c[3];
	char	*str;

	while (lst != NULL)
	{
		cmd = (int *)lst->content;
		c[0] = cmd[0] % 2 + 'A';
		c[1] = ' ';
		if (cmd[0] > 1)
			c[1] = 'R';
		c[3] = '\0';
		ft_putstr_fd(c, 1);
		ft_putstr_fd("->", 1);
		str = ft_itoa(cmd[1]);
		if (str)
		{
			ft_putstr_fd(str, 1);
			free(str);
		}
		write(1, "\n", 1);
		lst = lst->next;
	}
}

// Function to print out list of operators
void	print_out(t_list *lst)
{
	while (lst != NULL)
	{
		ft_putstr_fd((char *)lst->content, 1);
		lst = lst->next;
	}
}
