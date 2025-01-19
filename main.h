/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:24:18 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/19 21:10:58 by nefimov          ###   ########.fr       */
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
# define CMD 2
# define OUT 3

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
void	print_cmd(t_list *lst);
void	print_out(t_list *lst);

// List utils
int		get_int(t_list *lst);
int		get_nint(t_list *lst, unsigned int n);

// Sort operations
void	r_lst(t_list *lst[4], char c);
void	r_lst_ab(t_list *lst[4]);
void	rr_lst(t_list *lst[4], char c);
void	rr_lst_ab(t_list *lst[4]);
void	s_lst(t_list *lst[4], char c);
void	s_lst_pair(t_list *lst[4]);
void	ss_lst(t_list *lst[4]);
void	p_lst(t_list *lst[4], char c);

// Sort utils
int		lst_is_sorted_down(t_list *lst, int n);
int		lst_is_sorted_up(t_list *lst, int n);
int		get_median_value(t_list *lst, int *cmd);
int		get_n_minmax_value(t_list *lst, int *cmd, int n);

// Sort list
void	make_sort(int argc, char *argv[], t_list *lst[4], int len);
void	sort_lst(t_list *lst[4], int len, int to_btm);
void	sort_pair_a(t_list *lst[4], int len_a, int len_b);
void	sort_pair_b(t_list *lst[4], int len_a, int len_b);
void	sort_pair_ss(t_list *lst[4], int opr_a, int opr_b, char c);
void	sort_pair_rr(t_list *lst[4], int opr_a, int opr_b, char c);
void	divide_a(t_list *lst[4]);
void	divide_a_half(t_list *lst[4], int *cmd);
int		divide_a_move(t_list *lst[4], int to_move, int m);
void	divide_b(t_list *lst[4]);
void	divide_b_half(t_list *lst[4], int *cmd);
int		divide_b_move(t_list *lst[4], int to_move, int m);
void	divide_a_init(t_list *lst[4], int to_btm, int to_top);
void	divide_a_third_init(t_list *lst[4], int *cmd, int to_btm, int to_top);
int		divide_a_move_init(t_list *lst[4], int to_move, int m, int m_btm);
void	init_move_btn(t_list *lst[4], int *rr_back, int *to_move);
void	init_move_top(t_list *lst[4], int *rr_back, int *to_move);
void	return_numbers(t_list *lst[4]);
int		calc_opr_a(t_list *a, int len);
int		calc_opr_b(t_list *a, int len);

// Commands list
int		add_cmd_divide(t_list **cmd_lst, int c_lst, int num);
int		add_cmd_return(t_list **cmd_lst, int c_lst, int num);
int		*read_cmd(t_list *cmd_lst);
int		*get_cmd(t_list **cmd_lst);
int		init_cmd(t_list **cmd_lst, int len);

#endif