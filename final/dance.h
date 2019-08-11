/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dance.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:01:18 by ylila             #+#    #+#             */
/*   Updated: 2019/08/10 06:15:53 by yas              ###   ########.fr       */
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

t_dance				*create(char n_name, int n_coord);
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


void				hide_option(t_dance *node);
void				open_option(t_dance *node);
void				bad_options(t_dance *node, void (*f)(t_dance *));

#endif
