/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan     <@student.42kocaeli.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:30:57 by mkaplan           #+#    #+#             */
/*   Updated: 2023/11/21 17:30:58 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	ptr = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 1;
	if (n == 0)
		return (0);
	while (*ptr == *ptr2 && i < n)
	{
		ptr++;
		ptr2++;
		i++;
	}
	return (*ptr - *ptr2);
}
