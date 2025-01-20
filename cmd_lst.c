/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:40:57 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/20 17:03:11 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "libft.h"

// Add a return command to the list of commands
void	add_cmd_return(t_list *lst[LS], int c_lst, int num)
{
	int		*cmd;
	t_list	*node;

	cmd = read_cmd(lst[CMD]);
	if (cmd && cmd[0] >= AR)
	{
		if (cmd[0] != c_lst)
			cmd[1] -= num;
		else
			cmd[1] += num;
	}
	else
	{
		cmd = (int *) malloc(sizeof(int) * CMD_SIZE);
		if (cmd == NULL)
			clear_exit(lst, -2);
		cmd[0] = c_lst;
		cmd[1] = num;
		node = ft_lstnew(cmd);
		if (node == NULL)
			clear_exit(lst, -2);
		ft_lstadd_front(&lst[CMD], node);
	}
}

// Add a divide command to the list of commands
void	add_cmd_divide(t_list *lst[LS], int c_lst, int num)
{
	int		*cmd;
	t_list	*node;

	cmd = (int *) malloc(sizeof(int) * CMD_SIZE);
	if (cmd == NULL)
		clear_exit(lst, -2);
	cmd[0] = c_lst;
	cmd[1] = num;
	node = ft_lstnew(cmd);
	if (node == NULL)
		clear_exit(lst, -2);
	ft_lstadd_front(&lst[CMD], node);
}

// Read the first command in the list of commands
int	*read_cmd(t_list *cmd_lst)
{
	int	*cmd;

	if (cmd_lst)
		cmd = (int *) cmd_lst->content;
	else
		cmd = NULL;
	return (cmd);
}

// Read the first command in the list of commands
// and remove it from the list without removing content
int	*get_cmd(t_list **cmd_lst)
{
	t_list	*node;
	int		*cmd;

	cmd = read_cmd(*cmd_lst);
	if (*cmd_lst)
	{
		node = *cmd_lst;
		*cmd_lst = (*cmd_lst)->next;
		ft_lstdelone(node, del_none);
	}
	return (cmd);
}

// Function to free list node without content content
void	del_none(void *content)
{
	if (content)
		return ;
}
