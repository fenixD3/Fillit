/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 23:09:22 by ylila             #+#    #+#             */
/*   Updated: 2019/04/07 21:02:05 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t i;

	i = 0;
	while (*dest)
	{
		++dest;
		++i;
	}
	while (*src && nb > 0)
	{
		*dest = *src;
		++src;
		++dest;
		++i;
		--nb;
	}
	*dest = '\0';
	return (dest - i);
}
