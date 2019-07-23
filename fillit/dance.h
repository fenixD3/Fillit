/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dance.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:01:18 by ylila             #+#    #+#             */
/*   Updated: 2019/07/21 18:47:29 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DANCE_H
# define DANCE_H

typedef struct		s_dance
{
	char			*name;
	int				coord;
	int				jump;
	struct s_dance	*up;
	struct s_dance	*down;
	struct s_dance	*left;
	struct s_dance	*right;
}					t_dance;

t_dance				*create(const char *n_name, const int n_coord);
int					add_hor(t_dance **dance, t_dance *left, t_dance *right,
							t_dance *new);
int					add_ver(t_dance **dance, t_dance *up, t_dance *down,
							t_dance *new);

int					add_spacer(t_dance **head, t_dance *new, _Bool edge,
								t_dance **curr);
void				free_cage(t_dance **head, _Bool error);
t_dance				*make_cage(int side);

#endif
