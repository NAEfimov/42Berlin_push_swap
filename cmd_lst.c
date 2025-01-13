/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:40:57 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/13 12:43:28 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "libft.h"

// Add a command to the list of commands
// Return <0> if ok, <-1> if malloc error
int	add_cmd_check(t_list **cmd_lst, int lst, int num)
{
	int		*cmd_pr;
	int		*cmd;
	t_list	*node;

	
	cmd_pr = read_cmd(*cmd_lst);
	if (cmd_pr && cmd_pr[0] >= AR)
	{
		if (cmd_pr[0] != lst)
			cmd_pr[1] -= num;
		else
			cmd_pr[1] += num;		
	}
	else
	{
		cmd = (int *) malloc(sizeof(int) * CMD_SIZE);
		if (cmd == NULL)
			return (-1);	
		cmd[0] = lst;
		cmd[1] = num;
		node = ft_lstnew(cmd);
		if (node == NULL)
			return (-2);
		ft_lstadd_front(cmd_lst, node);
	}
	return (0);
}

int	add_cmd(t_list **cmd_lst, int lst, int num)
{
	int		*cmd;
	t_list	*node;

	cmd = (int *) malloc(sizeof(int) * CMD_SIZE);
	if (cmd == NULL)
		return (-1);
	cmd[0] = lst;
	cmd[1] = num;
	node = ft_lstnew(cmd);
	if (node == NULL)
		return (-2);
	ft_lstadd_front(cmd_lst, node);
	return (0);
}

// Read the first command in the list of commands
int	*read_cmd(t_list *cmd_lst)
{
	int 	*cmd;

	if (cmd_lst)
		cmd = (int *) cmd_lst->content;
	else
		cmd = NULL;
	return (cmd);
}

// Read the first command in the list of commands
// and remove it from the list
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

// Initialise the list of commands
// Return <0> if ok, <-1> if error
int	init_cmd(t_list **cmd_lst, int len)
{
	return (add_cmd(cmd_lst, A, len));
}

