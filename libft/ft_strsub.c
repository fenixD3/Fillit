/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 20:28:00 by ylila             #+#    #+#             */
/*   Updated: 2019/04/09 14:55:43 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char *substr;

	if (!s || !(substr = ft_strnew(len)))
		return (NULL);
	substr = ft_strncpy(substr, s + start, len);
	return (substr);
}
