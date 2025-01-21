/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:24:18 by nefimov           #+#    #+#             */
/*   Updated: 2025/01/21 18:29:40 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

# define A 0
# define B 1
# define CMD 2
# define OUT 3

# define AR 2
# define BR 3

# define CMD_SIZE 2
# define LS 4

// Exit
void	clean_lst_exit(t_list *lst[LS], int err);

// Read and check input args
int		*read_num(char *str);
void	del_none(void *content);
void	check_dup(int **num, t_list *lst);
int		read_args(int argc, char *argv[], t_list *lst[LS]);

// Print messages and lists
int		print_error(char *err_msg);
void	printv_lst(t_list *lst);
void	printh_lst(t_list *lst, char c);
void	print_cmd(t_list *lst);
void	print_out(t_list *lst);

// List utils
int		get_int(t_list *lst);
int		get_nint(t_list *lst, unsigned int n);
void	init_list(t_list *lst[LS]);
void	add_opr_out(t_list *lst[LS], char *str);

// Sort operations
void	r_lst(t_list *lst[LS], char c);
void	r_lst_ab(t_list *lst[LS]);
void	rr_lst(t_list *lst[LS], char c);
void	rr_lst_ab(t_list *lst[LS]);
void	s_lst(t_list *lst[LS], char c);
void	s_lst_pair(t_list *lst[LS]);
void	ss_lst(t_list *lst[LS]);
void	p_lst(t_list *lst[LS], char c);

// Sort utils
int		lst_is_sorted_down(t_list *lst, int n);
int		lst_is_sorted_up(t_list *lst, int n);
int		get_n_minmax_value(t_list *lst, int *cmd, int n);

// Sort list
void	make_sort(int argc, char *argv[], t_list *lst[LS], int len);
void	sort_lst(t_list *lst[LS], int len, int to_btm);
void	sort_pair_a(t_list *lst[LS], int len_a, int len_b);
void	sort_pair_b(t_list *lst[LS], int len_a, int len_b);
void	sort_triad_a_alone(t_list *lst[LS]);
void	sort_triad_b_alone(t_list *lst[LS]);
void	sort_pair_ss(t_list *lst[LS], int opr_a, int opr_b, char c);
void	sort_pair_rr(t_list *lst[LS], int opr_a, int opr_b, char c);
int		calc_opr_a(t_list *a, int len);
int		calc_opr_b(t_list *a, int len);
void	return_elements(t_list *lst[LS]);
// Divide list a
void	divide_a(t_list *lst[LS]);
void	divide_a_half(t_list *lst[LS], int *cmd);
int		divide_a_move(t_list *lst[LS], int to_move, int m);
// Divide list b
void	divide_b(t_list *lst[LS]);
void	divide_b_half(t_list *lst[LS], int *cmd);
int		divide_b_move(t_list *lst[LS], int to_move, int m);
// Init divide
void	divide_init_a(t_list *lst[LS], int to_btm, int to_top);
void	divide_init_a_third(t_list *lst[LS], int *cmd, int to_btm, int to_top);
int		divide_init_a_move(t_list *lst[LS], int to_move, int m, int m_btm);
void	init_move_btn(t_list *lst[LS], int *rr_back, int *to_move);
void	init_move_top(t_list *lst[LS], int *rr_back, int *to_move);

// Commands list
void	add_cmd_divide(t_list *lst[LS], int c_lst, int num);
void	add_cmd_return(t_list *lst[LS], int c_lst, int num);
int		*read_cmd(t_list *cmd_lst);
int		*get_cmd(t_list **cmd_lst);

#endif