/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dance.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:01:18 by ylila             #+#    #+#             */
/*   Updated: 2019/08/03 23:40:05 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DANCE_H
# define DANCE_H

typedef struct		s_dance
{
	char			name;
	int				coord;
	struct s_dance	*spacer;
	struct s_dance	*home;
	struct s_dance	*up;
	struct s_dance	*down;
	struct s_dance	*left;
	struct s_dance	*right;
}					t_dance;

t_dance				*create(const char n_name, const int n_coord);
int					add_spacer(t_dance *head, t_dance *new, _Bool edge,
																t_dance *curr);
void				free_cage(t_dance **head, _Bool error);
t_dance				*make_cage(int side);
int					add_cage(t_dance *right, t_dance *left, t_dance *new);
void				free_list(t_dance **head);
t_dance				*create_connct(t_dance *left, t_dance *right, t_dance *up,
																t_dance *down);
void				node_set_params(t_dance *curr, char n_name, int n_coord,
															t_dance *spacer);
void				increment_down_rownum(t_dance *curr);
void				increase_list(t_dance *head, int side, int numfig);
int					increase_cage(t_dance *head, int side);
int					add_increase_row(t_dance *left_sp, int step);
int					add_increase_middle_rows(t_dance *head, int side,
																int numfig);
int					add_increase_last_rows(t_dance *head, int side,
																int numfig);
int					increment_row_n_lines(t_dance *left_sp, int *lines,
																	int side);
int					lst_find_max_low_dgtnum(t_dance *spacer);

#endif
