/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:37:08 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/12 12:15:45 by nefimov          ###   ########.fr       */
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

void print_cmd(t_list *lst)
{
	int		*cmd;
	char	c[2];
	
	while (lst != NULL)
	{
		cmd = (int *)lst->content;
		c[0] = cmd[0] % 2 + 'A';
		c[1] = ' ';
		if (cmd[0] > 2)
			c[1] = 'R';
		printf(" |%i%c%c %2i|\n",cmd[0], c[0], c[1], cmd[1]);
		lst = lst->next;
	}
}
