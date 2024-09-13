/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan     <@student.42kocaeli.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:41:24 by mkaplan           #+#    #+#             */
/*   Updated: 2023/11/21 18:41:25 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*lastspot;

	lastspot = 0;
	if (c > 127)
		return ((char *)s);
	while (*s)
	{
		if (*s == c)
			lastspot = (char *)s;
		s++;
	}
	if (lastspot)
		return (lastspot);
	if (c == '\0')
		return ((char *)s);
	return (0);
}
