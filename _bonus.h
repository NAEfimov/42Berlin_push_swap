/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:32:55 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/21 14:46:01 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BONUS_H
# define _BONUS_H

#include "main.h"

# define BUFF_SIZE 100

void	clean_opr(char **opr);
char	*read_clean(char	*buff_str, char	*str);
char	*read_string(char *str);
char	**read_stdio(void);
int		check_operation(t_list *lst[LS], char *opr);
void	make_operations(t_list *lst[LS], char **opr);

#endif