/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:05:46 by ylila             #+#    #+#             */
/*   Updated: 2019/04/07 19:17:08 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;
	char			*ptr2new;

	if (!s || !f || !(new_str = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = 0;
	ptr2new = new_str;
	while (s[i])
	{
		*ptr2new++ = (*f)(i, s[i]);
		++i;
	}
	return (new_str);
}
