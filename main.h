/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:24:18 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/08 15:31:01 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "libft.h"

#ifndef MAIN_H
# define MAIN_H

int		*read_num(char *str);
void	del_int(void *content);
void	check_dup(int **num, t_list *lst);
int		read_args(int argc, char *argv[], t_list **lst);

int		print_error(void);
void	printv_lst(t_list *lst);
void	printh_lst(t_list *lst, char c);

#endif