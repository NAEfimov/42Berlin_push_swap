/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:24:18 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/17 15:12:18 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "libft.h"

# define A 0
# define B 1
# define AR 2
# define BR 3

# define CMD_SIZE 2

// Read and check input args
int		*read_num(char *str);
void	del_int(void *content);
void	del_none(void *content);
void	check_dup(int **num, t_list *lst);
int		read_args(int argc, char *argv[], t_list **lst);

// Print messages and lists
int		print_error(void);
void	printv_lst(t_list *lst);
void	printh_lst(t_list *lst, char c);
void 	print_cmd(t_list *lst);

// List utils
int		get_int(t_list *lst);
int		get_intn(t_list *lst, unsigned int n);

// Sort operations
void	r_lst(t_list **lst, char c);
void	r_lst_ab(t_list **lst_a, t_list **lst_b);
void	rr_lst(t_list **lst, char c);
void	rr_lst_ab(t_list **lst_a, t_list **lst_b);
void	s_lst(t_list **lst, char c);
void	ss_lst(t_list **lst_a, t_list **lst_b);
void	s_lst_pair(t_list **lst_a, t_list **lst_b);
void	p_lst(t_list **lst_a, t_list **lst_b, char c);

// Sort utils
int		lst_is_sorted_down(t_list *lst, int n);
int		lst_is_sorted_up(t_list *lst, int n);
int		get_median_value(t_list *lst, int *cmd);
int		get_n_minmax_value(t_list *lst, int *cmd, int n);

// Sort list
void 	make_sort(t_list *lst[2], int len);
void	sort_triad_down(t_list **lst, char c);
void	sort_triad_up(t_list **lst, char c);
void	sort_pair_a(t_list **lst_a, t_list **lst_b, int len_a, int len_b);
void	sort_pair_b(t_list **lst_a, t_list **lst_b, int len_a, int len_b);
void	return_numbers(t_list **lst_a, t_list **lst_b, int *cmd);
void	divide_lst_a(t_list **lst_a, t_list **lst_b, int *cmd, t_list **cmd_lst);
void	divide_lst_b(t_list **lst_a, t_list **lst_b, int *cmd, t_list **cmd_lst);
void	divide_lst_a_init(t_list **lst_a, t_list **lst_b, t_list **cmd_lst);

// Commands list
int		add_cmd(t_list **cmd_lst, int lst, int num);
int		add_cmd_check(t_list **cmd_lst, int lst, int num);
int		*read_cmd(t_list *cmd_lst);
int		*get_cmd(t_list **cmd_lst);
int		init_cmd(t_list **cmd_lst, int len);

#endif