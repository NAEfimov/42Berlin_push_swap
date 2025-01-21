/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:43:21 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/21 15:22:04 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_bonus.h"

// Clean allocated memory for the strings
char	*read_clean(char *buff_str, char *str)
{
	if (buff_str)
		free(buff_str);
	if (str)
		free(str);
	return (NULL);
}

// Read a string from stdinput
char	*read_string(char *str)
{
	char	*buff_str;
	char	*join_str;
	int		i;

	buff_str = ft_calloc(BUFF_SIZE + 1, sizeof(char));
	if (buff_str == NULL)
		return (NULL);
	i = 1;
	while (i != 0)
	{
		join_str = ft_strjoin(str, buff_str);
		if (join_str == NULL)
			return (read_clean(buff_str, str));
		free(str);
		str = join_str;
		i = read(0, buff_str, BUFF_SIZE);
		if (i == -1)
			return (read_clean(buff_str, str));
		buff_str[i] = '\0';
	}
	free(buff_str);
	return (str);
}

// Read a string from stdinput, split it by the lines
// and return as an array of strings with operations
char	**read_stdio(void)
{
	char	*str;
	char	**opr;

	str = ft_calloc(1, sizeof(char));
	if (str == NULL)
		return (NULL);
	str = read_string(str);
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	opr = ft_split(str, '\n');
	free(str);
	return (opr);
}
