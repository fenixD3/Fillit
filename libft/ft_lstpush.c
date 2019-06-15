/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 14:30:51 by ylila             #+#    #+#             */
/*   Updated: 2019/05/18 19:50:28 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alst, t_list *new)
{
	t_list *curr;

	if (alst && !*alst && new)
		*alst = new;
	else if (alst && *alst && new)
	{
		curr = *alst;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}
