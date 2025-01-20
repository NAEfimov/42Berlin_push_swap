/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:46:03 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/20 23:30:51 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

#define BUFF_SIZE 100

int main()
{
	char	*read_str;
	char	*str;
	char	*str_to_add;
	char	**opr;
	size_t	i;
	
	read_str = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (read_str == NULL)
		return (1);
	str = ft_strdup("");
	i = read(0, read_str, BUFF_SIZE);
	while (i != 0)
	{
		read_str[i] = '\0';
		str_to_add = ft_strjoin(str, read_str);
		free(str);
		str = str_to_add;
		i = read(0, read_str, BUFF_SIZE);
	}
	opr = ft_split(str, '\n');
	i = 0;
	while (opr[i])
	{
		printf("%s", opr[i]);
		i++;
	}
	free(str);
	free(read_str);
	return (0);
}