/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:40:23 by ylila             #+#    #+#             */
/*   Updated: 2019/08/10 06:15:53 by yas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*to;
	const char	*from;

	if (!dst && !src)
		return (NULL);
	to = (char *)dst;
	from = (const char *)src;
	while (n--)
		*to++ = *from++;
	return (dst);
}
