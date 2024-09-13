/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan     <@student.42kocaeli.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:39:26 by mkaplan           #+#    #+#             */
/*   Updated: 2023/11/21 18:39:27 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s1, int c)
{
	if (c > 127)
		return ((char *)s1);
	while (*s1)
	{
		if (*s1 == c)
			return ((char *)(s1));
		s1++;
	}
	if (c == '\0')
		return ((char *)s1);
	return ((char *)0);
}
