/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:24:18 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/10 15:52:20 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "libft.h"

#ifndef MAIN_H
# define MAIN_H

// Read and check input args
int		*read_num(char *str);
void	del_int(void *content);
void	check_dup(int **num, t_list *lst);
int		read_args(int argc, char *argv[], t_list **lst);

// Print messages and lists
int		print_error(void);
void	printv_lst(t_list *lst);
void	printh_lst(t_list *lst, char c);

// List utils
int	get_int(t_list *lst);
int	get_intn(t_list *lst, unsigned int n);

// Sort operations
void	r_lst(t_list **lst, char c);
void	rr_lst(t_list **lst, char c);
void	s_lst(t_list **lst, char c);
void	p_lst(t_list **lst_a, t_list **lst_b, char c);

// Sort utils
int	lst_is_sorted_down(t_list *lst, int n);
int	lst_is_sorted_up(t_list *lst, int n);

//Sort list
void	sort_triad_down(t_list **lst, char c);

#endif